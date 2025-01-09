#include "../common.h"

typedef vector<int> vec;

int main()
{
  /*
  std::multimap<char, int> mymm;

  mymm.insert(std::make_pair('x', 10));
  mymm.insert(std::make_pair('y', 20));
  mymm.insert(std::make_pair('z', 30));
  mymm.insert(std::make_pair('z', 40));
  mymm.insert(std::make_pair('z', 50));
  mymm.insert(std::make_pair('z', 60));
  std::multimap<char, int>::iterator it = mymm.find('z');

  typedef std::multimap<char, int>::iterator MMAPIterator;
  // It returns a pair representing the range of elements with key equal to 'c'
  std::pair<MMAPIterator, MMAPIterator> result = mymm.equal_range('z');
  for (MMAPIterator it = result.first; it != result.second; it++)
      std::cout << it->second << std::endl;
  */
  std::multimap<float, vec> Distance;
  Distance.insert(std::make_pair<float, vec>(1.00000, {10, 20}));
  Distance.insert(std::make_pair<float, vec>(1.00000, {214, 74}));
  Distance.insert(std::make_pair<float, vec>(1.00000, {78, 29}));
  Distance.insert(std::make_pair<float, vec>(1.50000, {214, 74}));
  Distance.insert(std::make_pair<float, vec>(1.90000, {78, 29}));
  typedef std::multimap<float, vec>::iterator disIterator;
  std::pair<disIterator, disIterator> result = Distance.equal_range(1.0000);
  for (disIterator it = result.first; it != result.second; it++)
  {
    vector<int> second = it->second;
    std::cout << "{" << second[0] << "," << second[1] << "}" << endl;
    // std::cout << it->second << std::endl;
  }

  //  mymm.erase(it);
  //  mymm.erase(mymm.find('z'));
  // print content:
  /*
  std::cout << "elements in mymm:" << '\n';
  std::cout << "y => " << mymm.find('y')->second << '\n';

  */
  // Total Elements in the range
  /*  int count = std::distance(result.first, result.second);
    std::cout << "Total values for key 'c' are : " << count << std::endl;

    mymm.find('z');*/

  // multimap<int, int> gquiz1; // empty multimap container

  //// insert elements in random order
  // gquiz1.insert(pair<int, int>(1, 40));
  // gquiz1.insert(pair<int, int>(2, 30));
  // gquiz1.insert(pair<int, int>(3, 60));
  // gquiz1.insert(pair<int, int>(6, 50));
  // gquiz1.insert(pair<int, int>(6, 10));

  // multimap<int, int>::iterator itr;
  // cout << "\nThe multimap gquiz1 is : \n";
  // cout << "\tKEY\tELEMENT\n";
  // for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
  //     cout << '\t' << itr->first << '\t' << itr->second
  //         << '\n';
  // }
  // cout << endl;

  // // adding elements randomly, to check the sorted keys property
  // gquiz1.insert(pair<int, int>(4, 50));
  // gquiz1.insert(pair<int, int>(5, 10));

  // // printing multimap gquiz1 again

  // cout << "\nThe multimap gquiz1 after adding extra "
  //         "elements is : \n";
  // cout << "\tKEY\tELEMENT\n";
  // for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
  //     cout << '\t' << itr->first << '\t' << itr->second
  //          << '\n';
  // }
  // cout << endl;

  // std::multimap<int, int>::iterator itr = gquiz1.find(6);

  //// assigning the elements from gquiz1 to gquiz2
  // multimap<int, int> gquiz2(gquiz1.begin(), gquiz1.end());

  //// print all elements of the multimap gquiz2
  // cout << "\nThe multimap gquiz2 after assign from "
  //         "gquiz1 is : \n";
  // cout << "\tKEY\tELEMENT\n";
  // for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
  //     cout << '\t' << itr->first << '\t' << itr->second
  //          << '\n';
  // }
  // cout << endl;

  //// remove all elements up to
  //// key with value 3 in gquiz2
  // cout << "\ngquiz2 after removal of elements less than "
  //         "key=3 : \n";
  // cout << "\tKEY\tELEMENT\n";
  // gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
  // for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
  //     cout << '\t' << itr->first << '\t' << itr->second
  //          << '\n';
  // }

  //// remove all elements with key = 4
  // int num;
  // num = gquiz2.erase(4);
  // cout << "\ngquiz2.erase(4) : ";
  // cout << num << " removed \n";
  // cout << "\tKEY\tELEMENT\n";
  // for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
  //     cout << '\t' << itr->first << '\t' << itr->second
  //          << '\n';
  // }

  // cout << endl;

  //// lower bound and upper bound for multimap gquiz1 key =
  //// 5
  // cout << "gquiz1.lower_bound(5) : "
  //      << "\tKEY = ";
  // cout << gquiz1.lower_bound(5)->first << '\t';
  // cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
  //      << endl;
  // cout << "gquiz1.upper_bound(5) : "
  //      << "\tKEY = ";
  // cout << gquiz1.upper_bound(5)->first << '\t';
  // cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
  //      << endl;

  return 0;
}
