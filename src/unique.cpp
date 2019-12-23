#include <iostream>
#include <vector>
#include <set>
#include <utf8cpp/utf8.h>

template<typename T> struct TD;

int main() {
	std::set<utf8::uint32_t> inputUnordered{};

	std::string buffer{};

	while (getline(std::cin, buffer)) {
		/* Don't want to lose the newline just because it's a delimeter. */
		if (!std::cin.eof())
			buffer += "\n";

		auto utf8Iterator = buffer.begin();

		while (utf8Iterator != buffer.end()) {
			uint32_t codePoint;

			try {
				codePoint = utf8::next(utf8Iterator, buffer.end());
			} catch (const utf8::not_enough_room &ignored) {
				std::cerr << "Invalid utf8 code-point found whilst processing stream.\n";
				continue;
			} catch (const utf8::invalid_utf8 &ignored) {
				std::cerr << "Invalid utf8 code-point found whilst processing stream.\n";
				continue;
			}

			auto [_unused, inserted] = inputUnordered.insert(codePoint);

			if (inserted) {
				std::u32string u32CodePointStr{ codePoint };
				std::string u8CodePointStr{};
				utf8::utf32to8(u32CodePointStr.begin(), u32CodePointStr.end(), std::back_inserter(u8CodePointStr));
				std::cout << u8CodePointStr;
			}
		}
	}

	return 0;
}
