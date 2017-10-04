type 
	pii=record
		x,y:longint;
	end;
var
	str:ansistring;
	ttt,c,mk,ans,z,t,mask,were,i,j,k,n:longint;
	p:array[0..22] of longint;
	cs:array[0..22,0..22] of longint;
	cur:array[0..22] of pii;
	dp:array[0..2097152] of longint;
	tt:boolean;
	tmp:pii;
Begin
	assign(input,'mutation.dat'); reset(input);
	assign(output,'mutation.sol'); rewrite(output);
	readln(n,k,ttt);
	read(str);
	for i:=0 to k-1 do read(p[i]);
	for i:=0 to k-1 do
		for j:=0 to k-1 do
			read(cs[i,j]);
	
	cur[0].x:=-1; cur[0].y:=-1;
	were:=0; mk:=1 shl k;
	fillchar(dp,sizeof(dp),0);
	
	for i:=n-1 downto 0 do begin
		mask:=0;
		t:=ord(str[i+1])-ord('A');
		were:=were or (1 shl t);
		for j:=0 to k-1 do begin
			if (cur[j].x=-1) then break;
			inc(dp[mask],cs[t,cur[j].y]);
			dec(dp[mask or (1 shl t)],cs[t,cur[j].y]);
			dec(dp[mask or (1 shl cur[j].y)],cs[t,cur[j].y]);
			inc(dp[mask or (1 shl t) or (1 shl cur[j].y)],cs[t,cur[j].y]);
			mask:=mask or (1 shl cur[j].y);
		end;
		for j:=0 to k-1 do begin
			if (cur[j].x=-1) or (cur[j].y=t) then begin
				tt:=false;
				if (cur[j].x=-1) then tt:=true;
				cur[j].x:=i; cur[j].y:=t;
				for z:=j-1 downto 0 do begin
					tmp:=cur[z];
					cur[z]:=cur[z+1];
					cur[z+1]:=tmp;
				end;
				if (tt) then begin
					cur[j+1].x:=-1;
					cur[j+1].y:=-1;
				end;
				break;
			end;
		end;
	end;
	
	ans:=0;
	for i:=0 to k-1 do begin
		for mask:=0 to were-1 do begin
			if ((mask and were)<>mask) then continue;
			if ((mask and (1 shl i))<>0) then inc(dp[mask],dp[mask xor (1 shl i)]);
		end;
	end;
	
	for mask:=0 to were-1 do begin
		if ((mask and were)<>mask) then continue;
		c:=dp[mask];
		for i:=0 to k-1 do if ((mask and (1 shl i))<>0) then inc(c,p[i]);
		if (c<=ttt) then inc(ans);
	end;
	
	writeln(ans);
end.