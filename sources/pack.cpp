#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;




struct Email {
	std::string nickname = "Antonio";
	std::string server = "mail";
};

struct Person {
	std::string  first_name = "Anton";
	std::string  last_name = "Antonov";
	Email        email;
	size_t       age = 34;
	std::string  phone = "8-999-999-00-00";
};

int main(int argc, char* argv[]) {
	std::string File;
	if (argc < 1)
		File = argv[1];
	else {
		std::cout << "You don't enter name of file";
	}
	Person Ex;
	json Person;
	std::ofstream ofst(File);
	Person["first_name"] = Ex.first_name;
	Person["last_name"] = Ex.last_name;
	Person["email"]["nickname"] = Ex.email.nickname;
	Person["email"]["server"] = Ex.email.server;
	Person["age"] = Ex.age;
	Person["phone"] = Ex.phone;
	ofst << Person;
	ofst.close();
	return 0;
}
