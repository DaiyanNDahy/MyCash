#include "bits/stdc++.h"
using namespace std;
int TranIdgenerator=100,otpGenerator=2418;
map<long long,int>mp;

class History{
public:
int TranId,Amount,Balance;
string Description;
long long number;
History(long long number,string D,int A, int B){
TranId=++TranIdgenerator; //constructor
Description=D;
Amount=A,Balance=B;
}
};
class Member{
public:
string accountHolder;
int accountNumber,pin,balance;
vector<History>v;
Member(){
//constructor
balance=0;
}
};
void FileOp(Member a){
ofstream fout;
fout.open("Accounts.txt",ios::app);
fout<<"Number: 0"<<a.accountNumber<<endl;
fout<<a.accountHolder<<endl;
fout<<"Balance: "<<a.balance<<endl;
fout<<"Pin: "<<a.pin<<endl;
fout<<endl;
fout.close();
}
vector<Member>accounts;
bool otphandle(){
int otp=++otpGenerator,given;
cout<<" myCash OTP: "<<otp<<endl;
cout<<" Enter OTP: ";
cin>>given;
return (given==otp);

}
long long getNumber(){
long long number=0;
string s;
bool f=0;
int x;
cin>>s;
x=s.size();
for(int i=0;i<x;i++){
if(!isdigit(s[i])) f=1;
number=number*10+s[i]-'0';
}
if(f||x!=11)
return -1;
return number;
}
void open_account(){
cout<<" Enter Mobile No. (11-digit): ";
long long number=getNumber();
string s;
int x,y;
if(number<0) {
cout<<" Invalid Mobile Number"<<endl;
return;
}
if(mp[number]){
cout<<" Member already exists"<<endl;
return;
}
Member object;
object.accountNumber=number;
cout<<" Enter Name: ";
getline(cin,s);
getline(cin,object.accountHolder);
cout<<" Enter pin(5-digit): ";
cin>>x;
cout<<" Reconfirm pin: ";
cin>>y;
if(x!=y)
cout<<" Pins must be same"<<endl;
if(x==y){
if(otphandle()) {

object.pin=x;
accounts.push_back(object);
FileOp(object);
mp[number]=accounts.size()-1;
cout<<" Registration is Successful"<<endl;
}
else cout<<" OTP does NOT matched"<<endl;
}
}
void close_account(long long number){
if(otphandle()) {
mp[number]=0;
cout<<" Remove is Successfull"<<endl;
}
else cout<<" OTP does NOT matched"<<endl;
}
void Deposit(long long number){
int n;
char con;
cout<<" Enter Amount: ";
cin>>n;
cout<<" Cash-in "<<n<<endl;
cout<<" Are you sure(Y?N)? ";
cin>>con;
if(con=='Y'){
accounts[mp[number]].balance+=n;
cout<<" Cash-in is Successful"<<endl;
History a(number,"Cash-in ",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
FileOp(accounts[mp[number]]);
}
}
void Withdraw(long long number){
cout<<" Enter Amount: ";
int n;
cin>>n;
if(accounts[mp[number]].balance<n)
cout<<" Insufficient Fund"<<endl;

else{
cout<<" Cash-out "<<n<<endl;
cout<<" Are you sure(Y/N)? ";
char s;
cin>>s;
if(s=='Y'){
if(otphandle()) {
accounts[mp[number]].balance-=n;
cout<<" Cash-out is Successfull"<<endl;
History a(number,"Cash-out ",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
FileOp(accounts[mp[number]]);
}
else cout<<" OTP does NOT matched"<<endl;
}
}
}
void Check(long long number){
cout<<" "<<”Balance: “<<accounts[mp[number]].balance<<endl;
}
void Update(long long number){
cout<<" Old Name: "<<accounts[mp[number]].accountHolder<<endl;
cout<<" New Name(Enter to ignore):";
string s;
getline(cin,s);
getline(cin,s);
if(s.size()) {
if(otphandle()) {
accounts[mp[number]].accountHolder=s;
cout<<" Update is Successfull"<<endl;
}
else cout<<" OTP does NOT matched"<<endl;
}
cout<<" Old Pin: *****"<<endl;
cout<<" New pin (enter to ignore): ";
string pingiven;
getline(cin,pingiven);

if(pingiven.size()){
string newpin;
cout<<" Confirm New pin: ";
cin>>newpin;
if(newpin==pingiven){
int x=0;
for(int i=0;i<newpin.size();i++)
x=x*10+(newpin[i]-'0');
if(otphandle()) {
accounts[mp[number]].pin=x;
cout<<" Update is Successfull"<<endl;
}
else cout<<" OTP does NOT matched"<<endl;
}
else cout<<" Pins must be same"<<endl;
}
FileOp(accounts[mp[number]]);
}
void Send(long long number){
cout<<" Enter Destination no.(11-digit): ";
long long dest=getNumber();
if(mp[dest]==0||dest<-1)
cout<<" Destination Mobile no. is invalid"<<endl;
else {
cout<<" Enter Amount: ";
int n;
cin>>n;
if(accounts[mp[number]].balance<n)
cout<<" Insufficient Fund"<<endl;
else {
cout<<" Sending "<<n<<" to 0"<<dest<<endl;
cout<<" Are you sure(Y/N)? ";
char s;
cin>>s;

if(s=='Y'){
if(otphandle()) {
accounts[mp[number]].balance-=n;
accounts[mp[dest]].balance+=n;
cout<<" Send Money is Successfull"<<endl;
History a(number,"Send Money ",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
}
else cout<<" OTP does NOT matched"<<endl;
}
}
}
FileOp(accounts[mp[number]]);
FileOp(dest);
}
void payBill(long long number){
cout<<" Enter Bill Type (Gas/Electricity/Water/Internet-1/2/3/4): ";
int type,n=1000;
cin>>type;
if(accounts[mp[number]].balance<n) cout<<" Insufficient fund"<<endl;
else {
cout<<" Your ";
if(type==1) cout<<"Gas";
if(type==2) cout<<"Electricity";
if(type==3) cout<<"Water";
if(type==4) cout<<"Internet";
cout<<" Bill: 1000"<<endl;
cout<<" Want to pay(Y/N)? ";
char s;
cin>>s;
if(s=='Y'){
if(otphandle()) {
accounts[mp[number]].balance-=n;
accounts[0].balance+=n;

cout<<" Bill Payment is Successfull"<<endl;
if(type==1) {
History a(number,"Gas Bill ",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
}
if(type==2){
History a(number,"Electricity Bill",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
}
if(type==3) {
History a(number,"Water Bill ",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
}
if(type==4){
History a(number,"Internet Bill ",n,accounts[mp[number]].balance);
accounts[mp[number]].v.push_back(a);
}
}
else cout<<" OTP does NOT matched"<<endl;
}
}
FileOp(accounts[mp[number]]);
}
int main(){
ofstream fout;
fout.open("Accounts.txt");
fout.close();
Member object;
accounts.push_back(object);
int option,option1;
while(1){
cout<<"*** MyCash Login** "<<endl<<endl;
cout<<"1. Login"<<endl;
cout<<"2. Register"<<endl;
cout<<"3. Exit"<<endl;
cout<<" Enter Your Option(1-3): ";
cin>>option;

if(option == 1){
cout<<" Enter Mobile NO.(11-digit): ";
long long number=getNumber();
if(number<0) {
cout<<" Invalid Mobile Number"<<endl;
cout<<" Press any key to go to main menu....."<<endl;
cout<<" ";
char ch;
cin>>ch;
}
else if(mp[number]==0) {
cout<<" Member NOT exists"<<endl;
cout<<" Press any key to go to main menu....."<<endl;
cout<<" ";
char ch;
cin>>ch;
}
else {
cout<<" Enter pin: ";
int pingiven;
cin>>pingiven;
if(pingiven!= accounts[mp[number]].pin) {
cout<<" Invalid login"<<endl;
continue;
}
while(1){
cout<<"********** MyCash Menu ********"<<endl;
cout<<endl;
cout<<"1. Update Me"<<endl;
cout<<"2. Remove Me"<<endl;
cout<<"3. Send Money"<<endl;
cout<<"4. Cash-in"<<endl;
cout<<"5. Cash-out"<<endl;
cout<<"6. Pay Bill"<<endl;
cout<<"7. Check Balance"<<endl;
cout<<"8. History"<<endl;
cout<<"9. Logout"<<endl;
cout<<" Enter Your option(1-9):";
cin>>option1;
if(option1==1) Update(number);
if(option1==2) {
close_account(number);
cout<<" Back to MyCash Login Menu"<<endl;
break;

}
if(option1==3) Send(number);
if(option1==4) Deposit(number);
if(option1==5) Withdraw(number);
if(option1==6) payBill(number);
if(option1==7) Check(number);
if(option1==8) {
cout<<" Tran ID Description Amount Balance"<<endl;
int sz=accounts[mp[number]].v.size();
for(int i=0;i<sz;i++){
cout<<" ";
int temp=accounts[mp[number]].v[i].TranId;
if(temp<1e6) cout<<" ";
if(temp<1e5) cout<<" ";
if(temp<1e4) cout<<" ";
if(temp<1e3) cout<<" ";
cout<<temp<<" "<<accounts[mp[number]].v[i].Description<<" ";
temp=accounts[mp[number]].v[i].Amount;
cout<<temp<<" ";
if(temp<1e5) cout<<" ";
if(temp<1e4) cout<<" ";
if(temp<1e3) cout<<" ";
if(temp<1e2) cout<<" ";
if(temp<10) cout<<" ";
temp=accounts[mp[number]].v[i].Balance;
cout<<temp;
if(temp<1e6) cout<<" ";
if(temp<1e5) cout<<" ";
if(temp<1e4) cout<<" ";
if(temp<1e3) cout<<" ";
if(temp<1e2) cout<<" ";
if(temp<10) cout<<" ";
cout<<endl;
}
}
if(option1==9) break;
if(option1<1||option1>9) cout<<" Invalid Option"<<endl;
cout<<" Press any key to go to main menu....."<<endl;
cout<<" ";
char ch;
cin>>ch;
}
}

}
else if(option==2) {
open_account();
cout<<" Press any key to go to main menu....."<<endl;
cout<<" ";
char ch;
cin>>ch;
}
else if(option==3) return 0;
else{
cout<<" Invalid Option"<<endl;
cout<<" Press any key to go to main menu....."<<endl;
cout<<" ";
char ch;
cin>>ch;
}
}
return 0;
}
