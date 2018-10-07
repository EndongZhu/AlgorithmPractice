#include <iostream>
#include <cstdio>
using namespace std ;

int main()
{
	int addr ;
	while(scanf("%x", &addr)!=EOF)
	{
		addr = addr & 0xffff ;
		int i = (addr-0x45c0) / (8*32) ;
		int j = ((addr-0x45c0) % (8*32)) / 8 ;
		int set = (addr >> 6) & 0x1f ;
		
		printf("i:%d j:%d set_id:%d\n", i, j, set) ;
	}
}
