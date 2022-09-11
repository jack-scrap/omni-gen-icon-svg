#include <string>
#include <iostream>

#define STRIDE 3

const std::string ws = " ";
const std::string sep = ",";

int main() {
	float vtc[] = {
		-0.26, 0.0, -0.26,
		0.16, 0.0, -0.26,
		-0.10, 0.0, -0.10,

		0.06, 0.0, -0.10,
		0.16, 0.0, -0.26,
		0.26, 0.0, -0.16,

		0.06, 0.0, -0.10,
		0.10, 0.0, -0.06,
		0.26, 0.0, -0.16,

		0.26, 0.0, 0.26,
		0.10, 0.0, -0.06,
		0.10, 0.0, 0.10,

		0.26, 0.0, 0.26,
		-0.16, 0.0, 0.26,
		0.10, 0.0, 0.10,

		-0.06, 0.0, 0.10,
		-0.16, 0.0, 0.26,
		-0.26, 0.0, 0.16,

		-0.06, 0.0, 0.10,
		-0.10, 0.0, 0.06,
		-0.10, 0.0, 0.06,

		-0.26, 0.0, 0.16,
		-0.10, 0.0, -0.10,
		-0.26, 0.0, -0.26
	};

	unsigned short idc[] = {
		0, 1, 2,

		2, 1, 3,

		4, 5, 6,

		6, 5, 7,

		8, 9, 10,

		10, 9, 11,

		12, 13, 14,

		14, 13, 15,

		16, 17, 18,

		18, 17, 19,

		20, 21, 22,

		22, 21, 23
	};

	std::string buff;

	buff += "M";
	buff += ws;

	for (int i = 0; i < sizeof idc / sizeof *idc; i++) {
		int idx = idc[i] * STRIDE;

		std::string cmd;

		cmd += std::to_string(vtc[idx]);
		cmd += sep;
		cmd += std::to_string(vtc[idx + 2]);

		if (i % 3 == 2) {
			cmd += ws;

			cmd += "Z";
		}

		if (i < (sizeof idc / sizeof *idc) - 1) {
			cmd += ws;
		}

		buff += cmd;
	}

	std::cout << buff << std::endl;

	return 0;
}
