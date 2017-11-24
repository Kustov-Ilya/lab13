#include <iostream>
#include <fstream>
#include<string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Email {
	string nickname;
	string server;
};

struct Person {
	string  first_name;
	string  last_name;
	Email   email;
	size_t  age;
	string  phone;
};

void Print(Person &pers) {
	std::cout << "First Name: " << pers.first_name << std::endl;
	std::cout << "Last Name: " << pers.last_name << std::endl;
	std::cout << "Mail" << pers.email.nickname << "@" << pers.email.server <<  std::endl;
	std::cout << "Age: " << pers.age << std::endl;
}

int main(int argc, char* argv[]) {
	string Path = argv[1];
	Person Pers;
	json j;
	ifstream file;
	file.open(Path);
	file >> j;
	file.close();
	Pers.first_name = j.at("first_name").get<std::string>();
	Pers.last_name = j.at("last_name").get<std::string>();
	Pers.age = j.at("age").get<size_t>();
	Pers.phone = j.at("phone").get<std::string>();
	Pers.email.nickname = j.at("email").at("nickname").get<std::string>();
	Pers.email.server = j.at("email").at("server").get<std::string>();
	Print(Pers);
	return 0;
}
