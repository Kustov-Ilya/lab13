#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


struct ExamplePerson{
	std::string  first_name = "Anton";
	std::string  last_name = "Antonov";
	std::string nickname = "Antonio";
	std::string server =  "mail";
	size_t age = 37;
	std::string phone = "8-999-999-00-00";
};



int main(int argc, char* argv[]) {
	std::string File;
	if(argc < 1)
		File = argv[1];
	else {
		std::cout << "You don't enter name of file";
	}
	ExamplePerson Ex;
	json Person;
	std::ofstream ofst(File);
	Person["first_name"] = Ex.first_name;
	Person["last_name"] = Ex.last_name;
	Person["email"]["nickname"] = Ex.nickname;
	Person["email"]["server"] = Ex.server;
	Person["age"] = Ex.age;
	Person["phone"] = Ex.phone;
	ofst << Person;
	ofst.close();
	return 0;
}
