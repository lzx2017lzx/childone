#!/usr/bin/lua
for word in string.gmatch("Hello lua user","%a+")
do
print(word)
end
