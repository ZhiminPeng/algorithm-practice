#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

string ShortestPath(const string& path) {

  vector<string> path_names;
  if (path.front() == '/') {
    path_names.push_back("/");
  }

  stringstream ss(path);
  string token;
  while (getline(ss, token, '/')) {

    if (token == "..") {
      if (path_names.empty() || path_names.back() =="..") {
        path_names.push_back(token);
      } else {
        if (path_names.back() == "/") {
          throw invalid_argument("Path error");
        }
        path_names.pop_back();
      }
      
    } else if (token != "." && token != "") {
      path_names.push_back(token);
    }

  }


  string result;
  if(!path_names.empty()) {
    result = path_names.front();

    for (int i = 1; i < path_names.size(); i++) {
      if( i == 1 && result == "/") {
        result += path_names[i];
      } else {
        result += "/" + path_names[i];
      }
    }
  }
  return result;
}

int main() {

  string test;
  while(true){
    cin >> test;
    cout << ShortestPath(test) << endl;
  }

}
