/* cool bag             shaped code*/
#include                   <iostream>
#include                      <cmath>
const float m[][2] = {{0.2,100},{0.15
,150},{0.1,135}};int main(){char type
;int h;std::cout<<" > Types of work:"
<<"A, B and C\n Enter your type and "
<<"hours you worked: ";std::cin>>type
>>h;if(toupper(type)-'A'+1<1||toupper
(type)-'A'+1>3)return-1;float netto=m
[toupper(type)-'A'][1]* abs((sin(h) -
pow(cos(h),3)*sin(h*h-4.2)+4.27) + m[
toupper(type)- 'A'][1]); std::cout <<
"\nsalary for "<<h<<"hours of "<<type
<<" work type >"<<"\n netto salary: "
<<netto<<"\n brutto salary:"<<netto*m
[ toupper( type) - 'A' ][0] << "\n";}