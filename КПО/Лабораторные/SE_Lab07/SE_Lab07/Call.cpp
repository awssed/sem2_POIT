#include"Call.h"
int _cdecl funA(int x, int y,int z) {
	return x + y + z;
}
int _stdcall funB(int x, int y) {
	return x * y;
}
int _fastcall funC(int x, int y, int z, int o) {
	return x + y + z + o;
}