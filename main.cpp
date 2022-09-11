#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define STRIDE 3

const unsigned int scale = 100;

const std::string fName = "icon.svg";

namespace svg {
	const std::string ws = " ";
	const std::string sep = ",";

	const std::string move = "M";
	const std::string close = "Z";
}

namespace path {
	const std::string sep = "/";

	std::string build(std::vector<std::string> entry) {
		std::string buff;

		for (int i = 0; i < entry.size(); i++) {
			buff += entry[i];

			if (i < entry.size() - 1) {
				buff += sep;
			}
		}

		return buff;
	}
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

	// Tokenize
	std::vector<std::string> tok;

	for (int i = 0; i < sizeof idc / sizeof *idc; i++) {
		if (!(i % STRIDE)) {
			tok.push_back(svg::move);
		}

		std::string cmd;

		int idx = idc[i] * STRIDE;

		cmd += std::to_string(vtc[idx] * scale);
		cmd += svg::sep;
		cmd += std::to_string(vtc[idx + 2] * scale);

		if (i % STRIDE == STRIDE - 1) {
			cmd += svg::close;

			cmd += svg::move;
		}

		tok.push_back(cmd);
	}

	// Serialize
	std::string pathBuff;
	for (int i = 0; i < tok.size(); i++) {
		pathBuff += tok[i];

		if (i < tok.size() - 1) {
			pathBuff += svg::ws;
		}
	}

	// Generate buffer
	std::vector<std::string> buff;

	buff.push_back("<?xml version=\"1.0\"?>");
	buff.push_back("	<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"52\" height=\"52\">");
	buff.push_back("		<g transform=\"translate(26,26)\">");
	buff.push_back("			<path d=\"" + pathBuff + "\" fill=\"rgb(255, 142, 65)\" />");
	buff.push_back("		</g>");
	buff.push_back("</svg>");

	// Write
	std::ofstream f;
	f.open(path::build({
		"o",
		fName
	}));

	for (const std::string& line : buff) {
		f << line << "\n";
	}

	f.close();

	return 0;
}
