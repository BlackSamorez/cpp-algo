#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<char, vector<char>> order;
vector<char> symbols = {'+', '*', '/', '-'};
vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<char> permitted(0), permitted_start(0), permitted_end(0), unary_minus(0);

vector<string> vectorized;

const bool SILENT = true;

void generate_right_order(){
    //after numbers
    for (int i = 0; i < 10; ++i){
        order[numbers[i]].insert(order[numbers[i]].end(), numbers.begin(), numbers.end());
        order[numbers[i]].insert(order[numbers[i]].end(), symbols.begin(), symbols.end());
        order[numbers[i]].push_back(')');
        order[numbers[i]].push_back('-');
    }
    //after operators
    for (int i = 0; i < 4; ++i){
        order[symbols[i]].insert(order[symbols[i]].end(), numbers.begin(), numbers.end());
        order[symbols[i]].push_back(')');
        order[symbols[i]].push_back('(');
        order[symbols[i]].push_back('-');
    }
    //after -
    order['-'].push_back('-');
    //after left bracket
    order['('].insert(order['('].end(), numbers.begin(), numbers.end());
    order['('].push_back('-');
    order['('].push_back('(');
    //after right bracket
    order[')'].insert(order[')'].end(), symbols.begin(), symbols.end());
    order[')'].push_back('-');
    order[')'].push_back(')');
    //allowed characters
    permitted.insert(permitted.end(), numbers.begin(), numbers.end());
    permitted.insert(permitted.end(), symbols.begin(), symbols.end());
    permitted.push_back('(');
    permitted.push_back(')');
    //allowed 1st character
    permitted_start.insert(permitted_start.end(), numbers.begin(), numbers.end());
    permitted_start.push_back('(');
    permitted_start.push_back('-');
    //allowed lasr character
    permitted_end.insert(permitted_end.end(), numbers.begin(), numbers.end());
    permitted_end.push_back(')');
    //precedes unary minus
    unary_minus.insert(unary_minus.end(), symbols.begin(), symbols.end());
    unary_minus.push_back('(');
}

void check_if_correct(string str){
    bool correct = true;
    int total_bracket = 0;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        if (find(order[str[i]].begin(), order[str[i]].end(), str[i + 1]) == order[str[i]].end()){
            correct = false;
        }
        if (str[i] == '('){
            total_bracket++;
        }
        if (str[i] == ')'){
            total_bracket--;
        }
        if (total_bracket < 0){
            correct = false;
        }
        if (find(permitted.begin(), permitted.end(), str[i]) == permitted.end()){
            correct = false;
        }
    }
    if (str[str.size() - 1] == '('){
        total_bracket++;
    }
    if (str[str.size() - 1] == ')'){
        total_bracket--;
    }
    if (total_bracket != 0){
        correct = false;
    }

    if (find(permitted.begin(), permitted.end(), str[str.size() - 1]) == permitted.end()){
        correct = false;
    }
    if (find(permitted_start.begin(), permitted_start.end(), str[0]) == permitted_start.end()){
        correct = false;
    }
    if (find(permitted_end.begin(), permitted_end.end(), str[str.size() - 1]) == permitted_end.end()){
        correct = false;
    }

    if(!correct){
        cout << "ERROR\n";
        exit(0);
    }
}

vector<string> vectorize(string str){
    vector<string> vectorized;
    bool minused = false;
    string number = "";
    for (int it = 0; it<str.size(); ++it){
        int a_number = 0;
        number = "";
        while (find(numbers.begin(), numbers.end(), str[it]) != numbers.end()){
            if (a_number == 0 and minused){
                number.push_back('-');
                minused = false;
            }
            a_number++;
            number.push_back(str[it]);
            it++;
        }
        if (a_number != 0){
            vectorized.push_back(number);
            //cout << "number\n";
            it--;
            continue;
        }
        if (it == 0 and str[it] == '-'){
            minused = true;
            //cout << "1minus\n";
            continue;
        }
        if ((it > 0) and (str[it] == '-') and (find(unary_minus.begin(), unary_minus.end(), str[it - 1]) != unary_minus.end())){
            minused = !minused;
            //cout << "minus\n";
            continue;
        }
        if (str[it] == '(' and minused){
            minused = false;
            vectorized.push_back("-(");
            continue;
        }
        vectorized.push_back(string(1, str[it]));
    }
    return vectorized;
}

//two numbers and operator
string calculate_first_rang(vector<string>& vec){
    //cout << "First rang input " << vec[0] << " " << vec[1] << " " << vec[2] << " size " << vec.size() << "\n"; 
    int lhs = stoi(vec[0]);
    int rhs = stoi(vec[2]);
    int ans;

    if (vec[1][0] == '+'){
        ans = lhs + rhs;
    }
    if (vec[1][0] == '-'){
        ans = lhs - rhs;
    }
    if (vec[1][0] == '*'){
        ans = lhs * rhs;
    }
    if (vec[1][0] == '/'){
        ans = lhs / rhs;
    }
    return to_string(ans);
}

bool is_bruh(string c){
    if (c == "(" or c == "-("){
        return true;
    } else {
        return false;
    }
}

bool mul_or_div(string c){
    if (c == "*" or c == "/"){
        return true;
    } else {
        return false;
    }
}

bool add_or_sub(string c){
    if (c == "+" or c == "-"){
        return true;
    } else {
        return false;
    }
}

//numbers and operators
vector<string> calculate_second_rang(vector<string>& vec){

    if (!SILENT){
        cout << "Second rang input ";
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }

    while (find_if(vec.begin(), vec.end(), mul_or_div) != vec.end()){
        auto place = find_if(vec.begin(), vec.end(), mul_or_div);
        vector<string> first_rang(3);
        copy(place - 1, place + 2, first_rang.begin());
        string first_rang_answer = calculate_first_rang(first_rang);
        vec.erase(place - 1, place + 2);

        if (!SILENT){
            cout << "First rang output " << first_rang_answer << "\n";
        }
        
        vec.insert(place - 1, first_rang_answer);
    }
    while (find_if(vec.begin(), vec.end(), add_or_sub) != vec.end()){
        auto place = find_if(vec.begin(), vec.end(), add_or_sub);
        vector<string> first_rang(3);
        copy(place - 1, place + 2, first_rang.begin());
        string first_rang_answer = calculate_first_rang(first_rang);
        vec.erase(place - 1, place + 2);

        if (!SILENT){
            cout << "First rang output " << first_rang_answer << "\n";
        }
        
        vec.insert(place - 1, first_rang_answer);
    }
    while (find(vec.begin(), vec.end(), "-") != vec.end()){
        auto place = find(vec.begin(), vec.end(), "-");
        vector<string> first_rang(3);
        copy(place - 1, place + 2, first_rang.begin());
        string first_rang_answer = calculate_first_rang(first_rang);
        vec.erase(place - 1, place + 2);

        if (!SILENT){
            cout << "First rang output " << first_rang_answer << "\n";
        }

        vec.insert(place - 1, first_rang_answer);
    }
    if (!SILENT){
        if (vec.size() != 1){
            for (int i = 0; i < vec.size(); ++i)
            {
                cout << vec[i] << " ";
            }
            cout << "failed second rang\n";
        }
    }
    return vec;
}

//numbers, operators and brackets
int calculate_third_rang(vector<string>& vec){

    if (!SILENT){
        cout << "Third rang input ";
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }

    while (find_if(vec.begin(), vec.end(), is_bruh) != vec.end()){
        auto left = find_if(vec.rbegin(), vec.rend(), is_bruh);
        auto right = find(--(left.base()), vec.end(), ")");
        vector<string> second_rang(distance(--(left.base()) + 1, right));
        copy(--(left.base()) + 1, right, second_rang.begin());
        vector<string> second_rang_answer = calculate_second_rang(second_rang);
        if (*--(left.base()) == "-("){
            if (second_rang_answer[0][0] != '-'){
                second_rang_answer[0] = second_rang_answer[0].insert(0, "-");
            } else {
                if (!SILENT){
                    cout << "Erasing zero at " << second_rang_answer[0] << "\n";
                }
                second_rang_answer[0].erase(0, 1);
            }
        }
        vec.erase(--(left.base()), right + 1);

        if (!SILENT){
            cout << "Second rang output ";
            for (int i = 0; i < second_rang_answer.size(); ++i)
            {
                cout << second_rang_answer[i] << " ";            
            }
            cout << "\n";
        }

        vec.insert(--(left.base()), second_rang_answer.begin(), second_rang_answer.end());
    }

    if (!SILENT){
        cout << "Final iteration input ";
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }

    return(stoi(calculate_second_rang(vec)[0]));
}

int main() {
    string input;
    getline(cin, input);
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    
    generate_right_order();
    check_if_correct(input);

    vectorized = vectorize(input);
    
    int answer = calculate_third_rang(vectorized);

    cout << answer;

cout << "\n";
return 0;
}