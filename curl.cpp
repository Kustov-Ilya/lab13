#include <iostream>
#include <thread>
#include <future>
#include <curl/curl.h>

int main(int argc, char * argv[]) {
	std::string URL;
	if (argc > 1) {
		URL = argv[1];
	}
	else {
		std::cout << "URL don't enter";
		return 0;
	}

	CURL * curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.yandex.ru");  //указатель на URL
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  //не проверять сертификат по протоколу SSL
		curl_easy_setopt(curl, CURLOPT_NOBODY, 1); //не включает документы 
		long response_code; 
		std::promise<CURLcode> processing;		//обработчик потока 
		std::future<CURLcode> response = processing.get_future();

		std::thread thread([curl, &processing]() {
			processing.set_value(curl_easy_perform(curl)); //блокирование передачи файлов. CURLE_OK, если успешно
		});

		thread.detach(); //сделать поток фотовым
		if (response.get() == CURLE_OK)
		{
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
			std::cout << response_code << std::endl;
		}
		else {
			std::cout << "The code is not successful" << std::endl;
		}
		curl_easy_cleanup(curl);
	}
	return 0;
}
