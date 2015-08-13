// Evaluate RPN expressions

int Eval(const string& RPN_expression) {

  stack<int> intemediate_val;
  stringstream ss(RPN_expression);
  string token;
  const char delim = ',';

  while (getline(ss, token, delim)) {

    if (token == '+' || token == '-' || token == '*' || token == '/') {

      int first = intemediate_val.top();
      intemediate_val.pop();
      
      int second = intemediate_val.top();
      intemediate_val.pop();

      int val = 0;
      switch (token) {
        case '+':
          val = first + second;
          break;
        case '-':
          val = first - second;
          break;
        case '*':
          val = first * second;
          break;
        case '/':
          val = first / second;
          break;
      }
      intemediate_val.push(val);
    } else {
      intemediate_val.push(atoi(token));
    }
  }
  return intemediate_val.top();
}
