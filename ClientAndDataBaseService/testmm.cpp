
all:out
out:mysqltool.cpp server.cpp client.cpp
	g++ mysqltool.cpp server.cpp -o server.out -I/usr/include/mysql -lmysqlclient
	g++ client.cpp -o client.out 
#	g++ mysqltool.cpp -o mysqltool.out -I/usr/include/mysql -lmysqlclient
#	g++ mongotool.cpp -o mongotool.out -std=c++11 -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/bsoncxx/v_noabi -I/usr/local/include/libbson-1.0 -L/usr/local/lib -lmongocxx -lbsoncxx
