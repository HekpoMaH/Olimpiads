unit f1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Memo1: TMemo;
    Button2: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}
{$O-}
var
    Ns,Ks:array [1..20000] of string[20];
    bNs,bKs:word;
    M1,M2,M3,M4:array [1..20000] of word;
    ImeF:string;
    NomT:word;

procedure Swap (var a:string; var b:string);
var
    c:Variant;
begin
    c:=a; a:=b; b:=c;
end;

function Min(a,b:word):word;
begin
    if a<b then Result:=a
    else
    Result:=b;
end;

procedure Sort;
var
    i,j:word;
    s:string;
begin
    for i:=1 to bNs-1 do
     for j:=i+1 to bNs do
      if Ns[i]>Ns[j] then
       begin
        s:=Ns[i]; Ns[i]:=Ns[j]; Ns[j]:=s;
       end;
end;

procedure ChetF;
var
    i:word;
    f:text;
    s:string;
begin
    if NomT<10 then
     s:='0'+IntToStr(nomT)
     else
     s:=IntToStr(NomT);
    ImeF:='file.'+s+'.in';
    assign(f,ImeF);
    reset(f);
     readln(f,bNs);
     for i:=1 to bNs do
      readln(f,Ns[i]);
     readln(f,bKs);
     for i:=1 to bKs do
      readln(f,Ks[i]);
    close(f);
    Sort;
end;

procedure ZapF;
var
    i:word;
    f:text;
    s:string;
begin
    if NomT<10 then
     s:='0'+IntToStr(nomT)
     else
     s:=IntToStr(NomT);
    ImeF:='file.'+s+'.in';
    assign(f,ImeF);
    rewrite(f);
     writeln(f,bNs);
     for i:=1 to bNs do
      writeln(f,Ns[i]);
     writeln(f,bKs);
     for i:=1 to bKs do
      writeln(f,Ks[i]);
    close(f);
end;

function WyrniNomNs(s:string):word;
var
    i,k:word;
begin
    k:=0;
    for i:=1 to bNs do
     if Ns[i]=s then
      begin
       k:=i;
       break;
      end;
    Result:=k;
end;

function ObrBrM1(i1,i2:word):word;
var
    s1,s2:string;
    br,i,d:word;
begin
    s1:=Ns[i1];
    s2:=Ns[i2];
    d:=length(s1);
    br:=0;
    for i:=1 to d do
     if s1[i]=s2[i] then
      inc(br)
      else
      break;
//    Result:=M1[i1]+length(s2)-br;
    Result:=br+1;
end;

procedure ObrM1;
var
    i:word;
begin
    m1[1]:=1;
    for i:=2 to bNs do
     begin
      if Ns[i][1]<>Ns[i-1][1] then
       begin
        m1[i]:=1;
       end
       else
       begin
        m1[i]:=Min(M1[i-1]+1,ObrBrM1(i-1,i));
       end;
     end;
// ������� ������� ������
    M2[bNs]:=M1[bNs];
    for i:=bNs downto 2 do
      if M1[i-1]-M2[i]>1 then M2[i-1]:=M2[i]+1
      else
      M2[i-1]:=M1[i-1];
// ������� ������� ������
// ������ � ������� ���� �� �������
// � �� ��������� � 2 ���������� �� �� ����� ��
// ��������� ���� - 1 ��������� �� ������ � ������� ������
// �� �� ��� �� ���������
    if M2[bNs]>2 then
     begin
      M3[bNs]:=2;
      for i:=bNs downto 2 do
        if M2[i-1]-M3[i]>1 then
         M3[i-1]:=M3[i]+1
         else
         M3[i-1]:=M2[i-1];
     end
     else
     for i:=1 to bNs do M3[i]:=M2[i];
// ������� ������� ������
// ������ e ������� ������ ����
// ������ �� ��������� ���� �� �� ������ � 1 ���������
// �� ������� ������
    M4[1]:=0;
    for i:=2 to bNs do
      if M2[i]-M4[i-1]>1 then
      M4[i]:=M4[i-1]+1
      else
      M4[i]:=M2[i];
    if M2[bNs]>1 then
     begin
      M4[bNs]:=1;
      for i:=bNs downto 2 do
        if M2[i-1]-M4[i]>1 then M4[i-1]:=M4[i]+1;
     end;
end;

procedure PechatM1;
var
    i:word;
    s:string;
begin
    for i:=1 to bNs do
     begin
      s:=IntToStr(M1[i]);
      Form1.Memo1.Lines.Add(Ns[i]+#9+s+#9+IntToStr(M2[i])+#9+
                            IntToStr(M3[i])+#9+IntToStr(M4[i]));
     end;
    Form1.Memo1.Lines.Add('');
    for i:=1 to bKs do
     begin
      Form1.Memo1.Lines.Add(Ks[i]);
     end;
    Form1.Memo1.Lines.Add('');
//    Form1.Memo1.Lines.SaveToFile('Resh.txt');
end;

procedure Resh;
var
    i,Sum,Nom,NomS:word;
    f:text;
    s:string;
begin
    Nom:=WyrniNomNs(Ks[1]);
    if Nom=1 then
     Sum:=0
     else
     Sum:=M4[Nom];
     NomS:=Nom;
     for i:=2 to bKs do
      begin
       Nom:=WyrniNomNs(Ks[i]);
       if NomS=1 then
        Sum:=Sum+Min(M4[Nom],abs(NomS-Nom))
        else
        Sum:=Sum+Min(M3[Nom],abs(NomS-Nom));
       NomS:=Nom;
      end;
    if NomT<10 then
     s:='0'+IntToStr(nomT)
     else
     s:=IntToStr(NomT);
    ImeF:='file.'+s+'.sol';
    Form1.Memo1.Lines.Add(IntToStr(Sum));
    assign(f,ImeF);
    rewrite(f);
     writeln(f,Sum);
    close(f);
end;

procedure ObrFajl;
var
    i,j,k:word;
    d,r,MaxD,MaxBuk:byte;
    c:char;
    Fl:boolean;
    Nom:word;
begin
    for i:=42 to 50 do
     begin
      NomT:=i;
      bNs:=i*400;
      bKs:=random(5000)+5000;
      MaxD:=7;
      MaxBuk:=15;
      Ns[1]:='a';
      for j:=2 to bNs do
       begin
        repeat
          Fl:=true;
          d:=random(MaxD)+1;
          r:=random(MaxBuk);
          c:=chr(ord('a')+r);
          Ns[j]:=c;
          for k:=1 to d do
           begin
            r:=random(MaxBuk)+1;
            c:=chr(ord('a')+r);
            Ns[j]:=Ns[j]+c;
           end;
          for k:=1 to j-1 do
           if Ns[j]=Ns[k] then
            begin
             Fl:=False;
             break;
            end;
         until Fl;
       end;
      Sort;
      Nom:=random(bNs)+1;
      Ks[1]:=Ns[Nom];
      for j:=2 to bKs do
       begin
        repeat
          Nom:=random(bNs)+1;
          Ks[j]:=Ns[Nom];
          Fl:=True;
          for k:=1 to j-1 do
           if Ks[j]=Ks[k] then
            begin
             Fl:=False;
             break;
            end;
        until Fl;
       end;
      ZapF;
     end;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
    i:word;
begin
    for i:=15 to 15 do
     begin
      NomT:=i;
      ChetF;
      ObrM1;
      PechatM1;
      Resh;
     end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
    ObrFajl;
end;

end.
