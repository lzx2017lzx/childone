app:getuserpass postuserpass postnearbydriver
mm.cgi:mm.c
	gcc mm.c -o mm.cgi
dd.cgi:dd.c
	gcc dd.c -o dd.cgi
print.out:print.c
	gcc -o $@ $^
testcplusplus.out:testcplusplus.cpp
	g++ -o $@ $^
getuserpass:getuserpass.cpp mysqllib.cpp opensslmd5API.h cJSON.c json.cpp
	g++ -o $@ $^ -I/usr/include/mysql -lmysqlclient -lcrypto

postuserpass:postuserpass.cpp mysqllib.cpp opensslmd5API.h cJSON.c json.cpp myredis.h 
	g++ -o $@ $^ -I/usr/include/mysql -lmysqlclient -lcrypto -lhiredis
postnearbydriver:postnearbydriver.cpp mysqllib.cpp opensslmd5API.h cJSON.c json.cpp myredis.h
	g++ -o $@ $^ -I/usr/include/mysql -lmysqlclient -lcrypto -lhiredis

.PHONY:clean
clean:
	@rm $@
