#include <iostream>
#include <curl/curl.h>

using namespace std;

size_t write_to_string(void* ptr, size_t size, size_t count, void* stream) {
	((string*)stream)->append((char*)ptr, 0, size * count);
	return size * count;
}

int main() {
	string url = "https://adventofcode.com/2024/day/2/input";
	CURL* curl = curl_easy_init();
	string response;
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
		curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	cout << response << endl;
	return 0;
}