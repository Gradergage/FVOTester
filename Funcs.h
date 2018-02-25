
std::string readFile1(const std::string& fileName)
{
    std::ifstream f(fileName.c_str());
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    std::string s(size, ' ');
    f.seekg(0);
    f.read(&s[0], size); // по стандарту можно в C++11, по факту работает и на старых компиляторах
    return s;
}
std::string readFile(const char* fileName)
{
    std::ifstream f(fileName);
    std::stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}
bool readFile3(std::string& s, const char* filename)
{
    std::ifstream fp(filename);
    if(! fp.is_open())
        return false;

    char nil = '\0';
    std::getline(fp, s, nil);
    fp.close();
    return (s.length() > 0);
}
