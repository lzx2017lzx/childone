#!/usr/bin/lua

t={"1","2","3"}

for v,k in pairs(t) do
	print(v .. ":"  .. k)
end

t[1]="hello"
for v,k in pairs(t) do
	print(v .. ":"  .. k)
end

tt={ he = "ll",wo = "ld" }
tt.he="mm"
for v,k in pairs(tt) do
	print(v .. ":"  .. k)
	print(tt.he)
end

