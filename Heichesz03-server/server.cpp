#include "server.h"
#include<QCryptographicHash>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlRecord>


#include "redis.h"
Server::Server(QObject *parent) : QObject(parent)
{
	db=QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("127.0.0.1");
	db.setDatabaseName("ICE");
	db.setUserName("root");
	db.setPassword("123456");
	if(!db.open())
	{
		cout<<"db.open fail"<<endl;
		exit(1);
	}
	server.listen(QHostAddress::Any,10099);

	connect(&server,SIGNAL(requestReady(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&))
			,this,SLOT(onRequestReady(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)));

}

void Server::onPostReady(HttpServerRequest &request, HttpServerResponse &response)
{
	cout<<"onPostReady in"<<endl;
	QByteArray data=request.readBody();
	qDebug()<<"request body:"<<data;

	QJsonDocument doc=QJsonDocument::fromJson(data);

	QJsonObject root=doc.object();
	QJsonObject resp;

	QString cmd=root.value("cmd").toString();

	qDebug()<<"cmd"<<cmd;

	if(cmd=="register")
	{
		cout<<"register success"<<endl;
		resp=reg(root);
	}
	else if(cmd=="login")
	{
		resp=login(root);

	}
	else if(cmd=="nearbyDriver")
	{
		cout<<"nearbyDriver works"<<endl;
		resp=nearbyDrivers(root);
	}
	else
	{
		resp.insert("result","error");
		resp.insert("reason","unkown command");
	}

	{
		QJsonDocument doc(resp);
		QByteArray buf=doc.toJson();
		response.end(buf);
	}



}

QJsonObject Server::reg(const QJsonObject & req)
{
	QJsonObject resp;
	QString username=req.value("username").toString();
	QString password=req.value("password").toString();

	QString md5Password=md5(password);



	QString sql=QString("insert into tuser(username,fpassword)values('%1','%2')").arg(username,md5Password);
	QSqlQuery query=db.exec(sql);
	if(query.lastError().type()!=QSqlError::NoError)
	{
		resp.insert("result","err");
		resp.insert("reason","open database error");

		return resp;
	}


	resp.insert("result","ok");
	return resp;
}

QString Server::md5(QString arg)
{

	QByteArray bb;
	bb=QCryptographicHash::hash(arg.toUtf8(),QCryptographicHash::Md5);
	return bb.toHex();



}
QJsonObject Server::nearbyDrivers(const QJsonObject &req)
{
	//    QString pusername=req.value("username").toString();
	//    double plat=req.value("lat").toDouble();
	//    double plng=req.value("lng").toDouble();
	int geohash=req.value("geohash").toInt();

	qDebug()<<"get nearby driver:"<<geohash;
	Redis redis;


	int driverCount=0;
	QJsonArray driversArr;
	static int off[]={0,1,-1,2,-2};
	for(int i=0;i<sizeof(off)/sizeof(off[0]);++i)
	{
		int geokey=geohash+off[i];
		QStringList drivers=redis.getSet(QString::number(geokey));
		foreach(QString driverName,drivers)
		{
			QJsonObject driverObj;
			driverObj.insert("name",driverName);
			qDebug()<<"nearbydrivers name:"<<driverName;
			driverObj.insert("lat",redis.getHashMember(driverName,"lat").toDouble());
			qDebug()<<"nearbydrivers lat:"<<redis.getHashMember(driverName,"lat");
			driverObj.insert("lng",redis.getHashMember(driverName,"lng").toDouble());
			qDebug()<<"nearbydrivers lng:"<<redis.getHashMember(driverName,"lng");
			driversArr.append(driverObj);
			driverCount++;
			if(driverCount>=10)
				break;
		}
		qDebug()<<"driverCount"<<driverCount;
		if(driverCount>10)
			break;
	}

	QJsonObject resp;
	resp.insert("drivers",driversArr);
	resp.insert("result","ok");
	return resp;
}
QJsonObject Server::login(const QJsonObject & req)
{
	QJsonObject resp;
	resp.insert("cmd","login");
	QString username=req.value("username").toString();
	QString password=req.value("password").toString();
	QString type=req.value("type").toString();
	double lat=req.value("lat").toDouble();
	double lng=req.value("lng").toDouble();
	int geohash=req.value("geohash").toInt();
	qDebug()<<"lat:"<<lat<<endl;
	qDebug()<<"lng:"<<lng<<endl;
	QString md5Password=md5(password);



	QString sql=QString("select *from tuser where username='%1'and fpassword='%2'").arg(username,md5Password);
	QSqlQuery query=db.exec(sql);
	if(query.lastError().type()!=QSqlError::NoError)
	{
		resp.insert("result","err");
		resp.insert("reason","open database error");

		return resp;
	}
	if(query.size()!=1)
	{
		resp.insert("result","err");
		resp.insert("reason","username or password error");

		return resp;
	}


	Redis redis;
	if(redis.addSet(type,username)!=0)
	{
		resp.insert("result","err");
		resp.insert("reason","redis insert set error");
		return resp;
	}

#if 0
	QJsonObject hash;
	hash.insert("status","0");
	hash.insert("lat","");
	hash.insert("lng","");
	hash.insert("type",d);
	if(!redis.addHash(username,hash)!=0)
	{

	}
#endif

#if 0
	redis.addHash(username,
			"status","0","lat",QString::number(lat).toUtf8().data(),

			"lng",QString::number(lng).toUtf8().data(),"type",type.toUtf8().data(),NULL);

	if(type=="d")
		redis.addSet(QString::number(geohash),username);
#endif
	redis.addHash(username,QStringList()<<"status"<<"lat"<<"lng"<<"type"<<"geohash",
			QStringList()<<"0"<<QString::number(lat)
			<<QString::number(lng)<<type<<QString::number(geohash));

	if(type=="d")
		redis.addSet(QString::number(geohash),username);

	if(type=="d")
		qDebug()<<"laosiji:"<<username<<"online...";
	else
		qDebug()<<"shuke"<<username<<"online...";
	\
#if 0

		redisContext*ctx=redisConnect("127.0.0.1",6379);

	QString cmd=QString("sadd %1 %2").arg(type,username);
	redisReply*ret=(redisReply*)redisCommand(ctx,cmd.toUtf8().data());
	if(ret==NULL)
	{
		resp.insert("result","err");
		resp.insert("reason","redis insert set error");

		redisFree(ctx);
		return;
	}



	redisFree(ctx);
#endif
	resp.insert("result","ok");

	return resp;
}

void Server::onRequestReady(Tufao::HttpServerRequest&request, Tufao::HttpServerResponse&response)
{
	response.writeHead(HttpResponseStatus::OK);
	if(request.method()!="POST")
	{

		response.end("no POST error");
		return;

	}

	cout<<"onRequestReady success"<<endl;
	connect(&request,&HttpServerRequest::end,[&](){

			onPostReady(request,response);


			});
}
