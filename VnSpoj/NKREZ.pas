const         fi=''; fo='';
type          C = Record
                  s,t: longint;
                  g: boolean;
                  end;
var           f: array[0..10001] of longint;
              e: array[0..10001] of C;
              n: longint;
              m: longint;
Procedure     Nhap;
    Var       i: longint;
    Begin
              Assign(input,fi);
              Reset(input);
              Readln(n);
              For i:=1 to n do
                    with e[i] do
                        begin
                            readln(s,t);
                            g:=false;
                        end;
              close(input);
    End;
Procedure     QS(L,R: longint);
    Var       i,j,x: longint;
              cc: C;
    Begin
              i:=L;
              j:=R;
              x:=e[random(R-L+1)+L].t;
              repeat
                  while  e[i].t<x do inc(i);
                  while e[j].t>x do dec(j);
                  if i<=j then
                      begin
                          cc:=e[i];
                          e[i]:=e[j];
                          e[j]:=cc;
                          inc(i);
                          dec(j);
                      end;
              until i>j;
              if L<j then QS(L,j);
              if i<R then QS(i,R);
    End;
Function      max(a,b: longint): longint;
    Begin
              if a>b then max:=a else max:=b;
    End;
Procedure     Xuly;
    Var       i,j: longint;
    Begin
              QS(1,n);
              for i:=1 to n do
                    begin
                          if e[i].g=False then
                                begin
                                        e[i].g:=True;
                                        f[i]:=e[i].t-e[i].s;
                                end;
                          for j:=i+1 to n do
                                if e[j].s>=e[i].t then
                                        begin
                                              f[j]:=Max(f[i]+e[j].t-e[j].s,f[j]);
                                              e[j].g:=True;
                                              m:=max(M,f[j]);
                                        end;
                          m:=max(M,f[i]);
                    end;
    End;
Procedure     Xuat;
    Begin
              Assign(output,fo);
              Rewrite(output);
              write(m);
              close(output);
    End;
BEGIN
              Nhap;
              Xuly;
              Xuat;
END.program ideone;