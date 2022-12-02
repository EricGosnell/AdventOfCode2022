#include <fstream>

using namespace std;

int main() {
    for (int i=2; i<=25; i++) {
        fstream file("day" + to_string(i) + ".cpp",fstream::out);
        file << "#include \"../aoc2022.h\"" << endl;
        file << endl;
        file << "int main() {" << endl;
        file << "    return 0;" << endl;
        file << "}" << endl;
    }

    return 0;
}
