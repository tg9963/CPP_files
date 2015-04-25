#include <iostream>
#include <list>
#include <climits>
using namespace std;

void print_max_path(list<int> &a, list<int> &b)
{
    list<int>::iterator start_a = a.begin(), start_b = b.begin();
    list<int>::iterator i = start_a, j = start_b;
    int sum_a = 0, sum_b = 0;

    // sentinels
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);

    // follow merge procedure since lists are sorted. maintain sums till we
    // hit a common node. at this point, print elements of the list with
    // the larger sum from its start point to here.
    // reset the sums now. set start points to here.
    // the loop ends when the common node INT_MAX is reached and everything of
    // use has been printed.
    while (i != a.end() && j != b.end()) {
        if (*i == *j) {
            if (sum_a > sum_b) {
                while (start_a != i) {
                    cout << *start_a << " ";
                    ++start_a;
                }
                start_b = j;
            } else {
                while (start_b != j) {
                    cout << *start_b << " ";
                    ++start_b;
                }
                start_a = i;
            }
            sum_a = sum_b = 0;
            ++i;
            ++j;
        } else if (*i < *j) {
            sum_a += *i;
            ++i;
        } else if (*i > *j) {
            sum_b += *j;
            ++j;
        }
    }

    // remove sentinels
    a.pop_back();
    b.pop_back();
    cout << endl;
}

int main()
{
    list<int> a,b;

    a.push_back(1);
    a.push_back(3);
    a.push_back(30);
    a.push_back(90);
    a.push_back(120);
    a.push_back(240);
    a.push_back(511);

    b.push_back(0);
    b.push_back(3);
    b.push_back(12);
    b.push_back(32);
    b.push_back(90);
    b.push_back(125);
    b.push_back(240);
    b.push_back(249);

    print_max_path(a, b);
}