app:highpropertyserver

object=highpropertyserver


highpropertyserver:JSONPROPERTYSERVER.cpp WRITEREADAVOIDPASTE.h cJSON.c json.cpp opensslmd5API.h mysqllib.cpp myredis.h
	g++ -o $@ $^ WRITEREADAVOIDPASTE.c -lpthread -I/usr/include/mysql -lmysqlclient -lcrypto -lhiredis

testredis:testredis.cpp
	g++ -o $@ $^ -lhiredis

cjsontest:testcjson.c cJSON.h
	gcc -o $@ $^ cJSON.c

teststringstream:teststringstream.cpp
	g++ -o $@ $^
.PHONY:clean
clean:
	rm $(object)
