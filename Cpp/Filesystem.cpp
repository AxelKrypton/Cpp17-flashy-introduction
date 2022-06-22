#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    const auto filePath {"bigFileToCopy"};
    if (fs::exists(filePath)) {
        const auto bigFileSize {fs::file_size(filePath)};
        fs::path tmpPath {"/tmp"};
        if (fs::space(tmpPath).available > bigFileSize) {
            fs::create_directory(tmpPath.append("example"));
            fs::copy_file(filePath, tmpPath.append("newFile"));
        }
    } else
        std::cout << "File \"" << filePath << "\" not found.\n";
}
