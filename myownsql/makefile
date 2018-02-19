all:out
out:mysqllib.cpp myserver.cpp client.cpp
	g++ mysqllib.cpp myserver.cpp -o server.out -I/usr/include/mysql -lmysqlclient -lcrypto
	g++ client.cpp -o client.out
testmysql:mysql.c
	gcc -o $@ $^ -I/usr/include/mysql -lmysqlclient
