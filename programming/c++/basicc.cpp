#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

std::vector<int> initializeVector(int n) {
  std::vector<int> a;
  std::vector<int>::iterator it;
  for (int i = 1; i <= n; i++) {
    a.push_back(i);
  }
  for (it = a.begin(); it != a.end(); it++) {
    std::cout << *it << " ";
  }
  return a;
}

std::vector<std::string> findLongestStrings(std::vector<std::string> v) {
  int maxLen = v.at(0).size();
  for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++) {
    if (maxLen < (*it).size()) {
      maxLen = (*it).size();
    }
  }
  std::vector<std::string> vec2;
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i).size() == maxLen) {
      vec2.push_back(v.at(i));
    }
  }
  return vec2;
}

int maxProductOfAdjacentElements(std::vector<int> v) {
  int max = v.at(0) * v.at(1);

  for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++) {
    int temp = (*it) * (*(it + 1));
    if (max < temp) {
      max = temp;
    }
  }
  return max;
}

std::vector<int> removeLastElement(std::vector<int> v) {
  v.pop_back();
  return v;
}

int sumOfFirstAndLastElement(std::vector<int> v) {
  return v.front() + v.back();
}

std::vector<int> removeElements(std::vector<int> v, int l, int r) {
  v.erase(v.begin() + l, v.begin() + r + 1);
  return v;
}

int sumOfFirstAndLastElement2(std::list<int> linkedList) {
  if (linkedList.empty()) {
    return -1;
  } else if (linkedList.size() == 1) {
    return linkedList.front();
  }
  return linkedList.front() + linkedList.back();
}

std::list<int> deleteFrontBack(std::list<int> l) {
  l.pop_front();
  l.pop_back();
  return l;
}

std::list<int> changeValue(std::list<int> l, int k, int x) {
  std::list<int>::iterator it = l.begin();
  advance(it, k - 1);
  *it = x;
  return l;
}

std::list<int> changeValue2(std::list<int> l, int first, int last) {
  std::list<int>::iterator it = l.begin();
  std::list<int>::iterator it2 = l.begin();

  advance(it, first - 1);
  advance(it2, last);

  return l;
}

int sumOfAllElements(std::list<int> l) {
  std::list<int>::iterator it = l.begin();
  int sum = *it;
  for (int i = 1; i <= l.size(); i++) {
    advance(it, i - 1);
    sum += (*it);
  }
  return sum;
}
int verifyFunction(std::vector<int> v) {
  std::list<int> l(v.begin(), v.end());

  return sumOfFirstAndLastElement2(l);
}

std::list<int> removeElements(std::list<int> l, int n) {
  std::list<int>::iterator j;
  for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    if ((*it) >= n) {
      j = it;
      it--;
      l.erase(j);
    }
  }
  return l;
}

std::vector<std::vector<int>> uniqueRows(std::vector<std::vector<int>> matrix) {
  std::set<std::vector<int>> sv;
  std::vector<std::vector<int>> v2;
  for (std::vector<std::vector<int>>::iterator it = matrix.begin();
       it != matrix.end(); it++) {
    if (!sv.count(*it)) {
      sv.insert(*it);
      v2.push_back(*it);
    }
  }
  return v2;
}

std::string secondOrder(std::vector<int> arr) {
  std::set<int> s;
  for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
    s.insert(*it);
  }

  std::set<int>::iterator it2 = s.begin();
  std::advance(it2, 1);

  if (s.size() > 1) {
    return std::to_string(*it2);
  } else {
    return "NO";
  }
}

std::string secondOrder2(std::vector<int> arr) {
  std::set<int> s(arr.begin(), arr.end());
  std::set<int>::iterator it = s.begin();
  std::advance(it, 1);
  if (s.size() > 1)
    return std::to_string(*it);
  else
    return "NO";
}

bool setFind(std::vector<int> arr, int k) {
  std::set<int> s(arr.begin(), arr.end());
  for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    if (*it == k) {
      return true;
    }
  }
  return false;
}
std::vector<std::string> mergeStringArr(std::vector<std::string> arr1,
                                        std::vector<std::string> arr2) {
  std::set<std::string> resSet(arr1.begin(), arr1.end());
  for (auto str : arr2) {
    auto search = resSet.find(str);
    if (search != resSet.end()) // found
    {
      resSet.erase(search);
    }
  }
  std::vector<std::string> res(resSet.begin(), resSet.end());
  return res;
}

std::vector<std::string> mergeStringArr2(std::vector<std::string> arr1,
                                         std::vector<std::string> arr2) {
  std::set<std::string> s1(arr1.begin(), arr1.end());
  for (std::vector<std::string>::iterator it = arr2.begin(); it != arr2.end();
       it++) {
    auto search = s1.find(*it);
    if (search != s1.end()) {
      s1.erase(search);
    }
  }
  std::vector<std::string> v;
  for (std::set<std::string>::iterator it = s1.begin(); it != s1.end(); it++) {
    v.push_back(*it);
  }
  return v;
}

std::vector<int> setFunction(std::vector<int> arr, int k) {
  std::set<int> s(arr.begin(), arr.end());
  std::vector<int> result;

  for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    if (*it > k) {
      result.push_back(*it);
      break;
    }
  }
  if (result.empty()) {
    result.push_back(-1);
  }

  if (s.find(k) != s.end()) {
    result.push_back(k);
  } else if (!result.empty()) {
    result.push_back(*result.begin());
  } else {
    result.push_back(-1);
  }

  return result;
}

int vectorBeautifull(std::vector<int> v) {
  std::set<int> s(v.begin(), v.end());
  return v.size() - s.size();
}

/*int cyclicShift(std::string a) {
        std::set<char> set_a(a.begin(),a.end());
        std::set<std::string> s;

        std::set<char> temset_a(a.begin(), a.end());
        std::set<std::string> result;

        for (std::set<char>::reverse_iterator it = s.rbegin(); it != s.rend();
it++) { std::string temp_s=""; temp_s.push_back(*temset_a.end());
                temset_a.erase(*temset_a.end());
                for (std::set<char>::iterator it = temset_a.begin(); it !=
temset_a.end(); it++) { temp_s.push_back(*it);
                }

                result.insert(temp_s);
                //set value for new loop
                temset_a.insert(temp_s.begin(), temp_s.end());
        }
        return s.size();
}*/
std::string diversity(std::string str, int k) {
  std::set<char> s(str.begin(), str.end());

  if (str.size() < k) {
    return "impossible";
  } else if (str.size() >= k) {
    return std::to_string(str.size() - s.size());
  }
}

std::string diversity2(std::string str, int k) {
  std::set<char> s(str.begin(), str.end());

  if (str.size() < k) {
    return "impossible";
  } else {
    if (s.size() >= k) {
      return std::to_string(0);
    } else {
      return std::to_string(k - s.size());
    }
  }
}

std::vector<int> popMin(std::vector<int> arr) {
  std::stack<int> st_min, st;
  std::vector<int> res, temp, res2;
  for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
    st.push(*it);
  }
  for (std::vector<int>::reverse_iterator it = arr.rbegin(); it != arr.rend();
       it++) {
    temp.push_back(*it);
  }
  int i = 0;
  while (!st.empty()) {
    // tim gia tri nho nhat
    int min = *temp.begin();
    for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
      if (min > *it) {
        min = *it;
      }
    }

    temp.erase(temp.begin());
    st.pop();
    st_min.push(min);

    i++;
  }
  while (st_min.empty() == false) {
    res.push_back(st_min.top());
    st_min.pop();
  }
  for (std::vector<int>::reverse_iterator it = res.rbegin(); it != res.rend();
       it++) {
    res2.push_back(*it);
  }
  return res2;
}

std::vector<int> popMin2(std::vector<int> arr) {
  std::stack<int> st_min;
  std::vector<int> res;
  st_min.push(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] >= st_min.top())
      st_min.push(st_min.top());
    else
      st_min.push(arr[i]);
  }
  while (st_min.empty() == false) {
    res.push_back(st_min.top());
    st_min.pop();
  }
  return res;
}

std::vector<int> stackConcat(std::vector<int> a, std::vector<int> b) { // sai
                                                                       // bet
  std::stack<int> st1, st2;
  std::vector<int> v;
  for (int i = 0; i < a.size(); i++) {
    st1.push(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    st2.push(b[i]);
  }
  std::stack<int> st3;

  while (!st1.empty() && st2.empty()) {
    if (st1.empty() && !st2.empty()) {
      while (!st2.empty()) {
        if (st2.top() != st3.top()) {
          st3.push(st2.top());
        }
        st2.pop();
      }
    } else if (!st1.empty() && st2.empty()) {
      while (!st1.empty()) {
        if (st1.top() != st3.top()) {
          st3.push(st1.top());
        }
        st1.pop();
      }
    } else if (st1.top() < st2.top()) {
      if (st1.top() != st3.top()) {
        st3.push(st1.top());
      }
      st1.pop();
    } else if (st1.top() > st2.top()) {
      if (st2.top() != st3.top()) {
        st3.push(st2.top());
      }
      st2.pop();
    } else if (st1.top() == st2.top()) {
      if (st1.top() != st3.top()) {
        st3.push(st1.top());
      } else {
        st1.pop();
        st2.pop();
      }
    }
  }

  while (!st3.empty()) {
    v.push_back(st3.top());
    st3.pop();
  }
  return v;
}

std::vector<int> stickSpan(std::vector<int> arr) {
  // tính k.cách của thanh gỗ i tới thanh gỗ bên Trái, Cao hơn nó
  // arr: mảng chứa chiều cao các thanh gỗ

  std::stack<int> s;
  std::vector<int> r; // mảng kết quả

  s.push(0);
  r.push_back(1);
  // thanh gỗ đầu tiên ko có thanh bên trái -> mặc định k.c là 1
  // vì chỉ xét bên trái <=> stack ban đầu chỉ chứa thanh thứ 0

  int n = arr.size();
  for (int i = 1; i < n; i++) {

    // Mục đích lặp con: Tìm thanh gỗ bên trái (<=> thuộc stack) cao hơn thanh
    // gỗ i
    while (!s.empty() && arr[s.top()] <= arr[i]) {
      s.pop();
    }
    // nếu stack chứa độ cao 1 thanh nào đó nhưng thấp hơn thanh i ->xóa

    r.push_back((s.empty()) ? (i + 1) : (i - s.top()));
    // nếu stack rỗng <=> thanh i cao nhất => k.c = k.c của i +1
    // nếu có thanh cao hơn i => k.c = k.c của i - k.c thanh đó

    s.push(i);
    // thêm độ cao thanh i vào stack
  }

  return r;
}
std::string encodeString(std::string s) {
  // s=aabc => v=a, count=1 => a==a count++, a!=b stop, v=a2=>
  // v=b,count=1 => b!=c stop,v=a2b1
  // must browser for each word
  std::vector<char> v;
  int count = 1;
  v.push_back(s[0]);
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      if (s[i] == s[j]) {
        count++;
      } else {
        v.push_back(char(count));
        v.push_back(s[j]);
        count = 1;
      }
    }
  }
}

void bitSetTest(int n) {
  // std::bitset<n> foo(n);
  // std::cout << foo;
}

int main() {
  int n1 = 5, n2 = 6;
  while (n1 != 0 || n2 != 0) {
    std::cout << "AAAA" << std::endl;
    if (n1 > 0)
      n1--;

    if (n2 > 0)
      n2--;
  }
  std::string str;
  str = "aabc";
  std::string res;

  res = encodeString(str);
  std::cout << "RESULT IS " << res << std::endl;
  return 0;
}
