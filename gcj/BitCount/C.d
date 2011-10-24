import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.bigInt;
import std.math;

int readInt() { int x; scanf("%d", &x); return x; }
long readLong() { long x; scanf("%lld", &x); return x; }
string readString(int length = 1010) { char[] buf = new char[length]; scanf("%s", buf.ptr); return to!string(buf.ptr); }
BigInt readBigInt(int length = 1010) { char[] buf = new char[length]; scanf("%s", buf.ptr); return BigInt(to!string(buf.ptr)); }
void writeTC(int tc) { write("Case #", tc, ": "); }
void chmin(T)(ref T t, T f) { if (t > f) t = f; }
void chmax(T)(ref T t, T f) { if (t < f) t = f; }



void main(string[] args) {
	
	
	for (int TC = readInt, tc = 1; tc <= TC; ++tc) {
		long x = readLong;
		long ans = 0;
		for (long k = 1; x; k <<= 1) {
			long y = x & 1;
			if (!y) y = 2;
			ans += y;
			x -= y;
			x >>= 1;
		}
		writeTC(tc); writeln(ans);
	}
}

