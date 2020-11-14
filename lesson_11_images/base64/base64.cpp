#include <iostream>

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

char * translate_block(const char * block, int shift) {
	char * new_block = new char[4];
	new_block[0] = alphabet[block[0 + shift] >> 2];
	new_block[1] = alphabet[((block[0 + shift] & ~(~0 << 2)) << 4) + (block[1 + shift] >> 4)];
	new_block[2] = alphabet[((block[1 + shift] & ~(~0 << 4)) << 2) + (block[2 + shift] >> 6)];
	new_block[3] = alphabet[block[2 + shift] & ~(~0 << 6)];
	return new_block;
}

char * translate(const char * msg) {
	int len = strlen(msg);
	int add = (3-(len % 3))%3;
	char * msg1 = new char[len + add];
	for (int i = 0; i < len; i += 1)
		msg1[i] = msg[i];
	int new_len = len + add;
	for (int i = len; i < new_len; i += 1)
		msg1[i] = 0;

	const char * msg1_const = (const char *)msg1;
	char * translated_block;
	char * translated_msg = new char[new_len/3*4 + 1];
	int steps_max = new_len / 3;
	for (int step = 0; step < steps_max; step += 1) {
		translated_block = translate_block(msg1_const, step*3);
		for (int i = 0; i < 4; i += 1)
			translated_msg[step * 4 + i] = translated_block[i];
		delete[] translated_block;
	}
	if (add > 0)
		translated_msg[new_len/3*4 - 1] = '=';
	if (add > 1)
		translated_msg[new_len/3*4 - 2] = '=';
	translated_msg[new_len / 3 * 4] = '\0';
	return translated_msg;
}

int main(){
}