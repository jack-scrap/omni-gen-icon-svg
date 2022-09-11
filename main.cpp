#include <string>
#include <fstream>
#include <iostream>

#define STRIDE 3

const unsigned int scale = 100;

namespace svg {
	const std::string ws = " ";
	const std::string sep = ",";

	const std::string move = "M";
	const std::string close = "Z";
}

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

	buff += svg::move;

	buff += svg::ws;

	for (int i = 0; i < sizeof idc / sizeof *idc; i++) {
		int idx = idc[i] * STRIDE;

		std::string cmd;

		cmd += std::to_string(vtc[idx] * scale);
		cmd += svg::sep;
		cmd += std::to_string(vtc[idx + 2] * scale);

		if (i % 3 == 2) {
			cmd += svg::ws;

			cmd += svg::close;

			cmd += svg::ws;

			cmd += svg::move;
		}

		if (i < (sizeof idc / sizeof *idc) - 1) {
			cmd += svg::ws;
		}

		buff += cmd;
	}

	std::ofstream f;
	f.open("o/icon.svg");

	f << "<?xml version=\"1.0\"?>" << "\n";
	f << "	<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"52\" height=\"52\">" << "\n";
	f << "		<g transform=\"translate(26,26)\">" << std::endl;
	f << "			<path d=\"" << buff << "\" fill=\"rgb(255, 142, 65)\" />" << "\n";
	f << "		</g>" << "\n";
	f << "</svg>" << "\n";

	f.close();

	return 0;
}
