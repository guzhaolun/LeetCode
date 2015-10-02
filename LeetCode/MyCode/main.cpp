#include <iostream>
#include <string>
#include <vector>
#include "44. wildcard_matching.h"
#include "45. jump_game_ii.h"
#include "46. permutations.h"
#include "50. N-queens.h"
#include "51. N_queens_ii.h"
#include "53. spiral_matrix.h"
#include "60. permutation-sequence.h"
#include "64. minimum_path_sum.h"
#include "65. valid_number.h"
#include "66. plus_one.h"
#include "67. add_binary.h"
#include "68. text_justification.h"
#include "69 sqrt(x).h"
#include "70 climbing_stairs.h"
#include "71 simplify_path.h"
#include "72. edit-distance.h"
#include "73. set_matrix_zeros.h"
#include "74. search_a_2D_matrix.h"
#include "75. sort_colors.h"
#include "76 minimum_window_substring.h"
#include "77. combinations.h"
#include "78. subsets.h"
#include "79. search_word.h"
#include "81. searchj_in_rotated_sorted_array_ii.h"
//#include "82. remove_duplicates_sorted_list_ii.h"
#include "84. largest_rectangle_in_histogram.h"
#include "85. maximal_rectangle.h"
//#include "86. partition_list.h"
#include "87. scramble_string.h"
#include "88. merge_sorted_array.h"
#include "89. gray_code.h"
#include "91 decode_ways.h"
#include "92. reverse_linked_list_ii.h"
#include "93. restore_ip_address.h"
#include "97. interleaving_string.h"
#include "99. recover_binary_search_tree.h"
#include "115. distinct_subsequences.h"
#include "119. pascal's_triangle_ii.h"
#include "118. pascal's triangle.h"
#include "127. word_ladder.h"
#include "126. word_ladder_ii.h"
#include <unordered_set>
#include "131. palindrome_partitioning.h"
#include "132. palindrome_partition_ii.h"
#include "134. gas_station.h"
#include "139. word_break.h"
#include "140. word_break_ii.h"
#include "143. reorder_list.h"
#include "145. binary_tree_postorder_traversal.h"
#include "147. insertion_sort_list.h"
#include "148. sort_list.h"
#include "151. reverse_words_in_string.h"
#include "150. evaluate_reverse_polish_notation.h"
#include "152. maximum_product_subarray.h"
#include "162. find_peak_element.h"
#include "165. compare_version_numbers.h"
#include "168. excel_sheet_column_title.h"
#include "172. factorial_trailing_zeroes.h"
#include "166. fraction_to_recurring_decimal.h"
#include "179. largests_number.h"
#include "174. dungeon_game.h"
#include "187. repeated_dna_sequences.h"
#include "188. best_time_to_buy_and_sell_stock_iv.h"
#include "191. hamming_weight.h"
#include "190. reverse_bit.h"
#include "202. happy_number.h"
#include "207. course_schedule.h"
//#include "208. implement_trie.h"
#include "209. minimum_size_subarray_sum.h"
#include "210. course_schedule_ii.h"
#include "211. add_and_search_word.h"
#include "214. shortest_palindrome.h"
#include "215. kth_largest_number_in_a_string.h"
#include "216. combination_sum_iii.h"
#include "217. contains_duplicate.h"
#include "218. the_skyline_problem.h"
#include "223. rectangle_area.h"
#include "221. maximal_square.h"
#include "224. basic_calculator.h"
#include "227. basic_calculator_ii.h"
#include "233. number_of_digit_one.h"
//#include "236. lowest_common_ancestor_of_binary_tree.h"
#include "257. binary_tree_paths.h"
#include "241. different_ways_to_add_parentheses.h"
#include "264. ugly_number_ii.h"
#include "279. perfect_squares.h"
#include "273. integer_to_english_words.h"
#include "282. expression_and_operators.h"
using namespace std;

int main()
{
	/*Solution44 sol;
	bool a = sol.isMatch2("cddabbac","c*ab*c");
	cout << a << endl;*/

	/*Solution45 sol;
	int a[5] = { 2, 3, 1, 1, 4 };
	vector<int> nums(a,a+5);
	int s = sol.jump2(nums);*/
	/*Solution46 sol;
	int a[1] = { 1 };
	vector<int> nums(a, a + 1);
	sol.permute2(nums);*/

	//Solution50 sol;
	//vector<vector<string>> res = sol.solveNQueens(8);

	/*Solution51 sol;
	int res = sol.totalNQueens(8);
	cout << res << endl;*/

	//Solution53 sol;
	//int a[3] = { 1, 2, 3 };
	//vector<int> nums1(a, a + 3);
	//int a1[3] = { 4, 5, 6 };
	//vector<int> nums2(a1, a1 + 3);
	//int a2[3] = { 7, 8, 9 };
	//vector<int> nums3(a2, a2 + 3);
	//vector<vector<int>> matrix;
	//matrix.push_back(nums1);
	//matrix.push_back(nums2);
	//matrix.push_back(nums3);
	//vector<int> res = sol.spiralOrder(matrix);

	//Solution60 sol;
	//string res = sol.getPermutation(3, 2);

	//Solution64 sol;
	//vector<int> a;
	//a.push_back(1);
	//a.push_back(2);
	//vector<int> a1;
	//a1.push_back(1);
	//a1.push_back(1);
	//vector<vector<int>> grid;
	//grid.push_back(a);
	//grid.push_back(a1);
	//int res = sol.minPathSum(grid);

	//Solution65 sol;
	//bool res = sol.isNumber(" .9");

	//Solution67 sol;
	//string res = sol.addBinary("1", "111");

	/*Solution68 sol;
	string a[7] = { "Here", "is", "an", "example", "of", "text", "justification." };
	vector<string> s(a, a + 7);
	string b="a";
	vector<string> s1;
	s1.push_back(b);
	vector<string> res = sol.fullJustify(s,14);*/

	/*Solution69 sol;
	int res = sol.mySqrt(2147395599);
	int res2 = sol.mySqrt2(2147395599);*/

	//Solution70 sol;
	//int res = sol.climbStairs(10);
	//int res1 = sol.climbStairs2(10);

	/*Solution71 sol;
	string res = sol.simplifyPath("/a/./b/../../c/");*/

	//Solution72 sol;
	//int res = sol.minDistance("", "ebca");

	//vector<int> a;
	////a.push_back(0);
	//a.push_back(1);
	//vector<vector<int>> matrix;
	//matrix.push_back(a);
	//Solution74 sol;
	//bool res=sol.searchMatrix(matrix, 2);

	//Solution75 sol;
	//int a[8] = { 2, 0, 1, 2, 0, 0, 1, 1 };
	//vector<int> nu(a,a+8);
	////sol.sortSolors(nu);
	//sol.sortColors2(nu);

	/*Solution76 sol;
	string res = sol.minWindow("acbdbaab", "aabd");
	string res2 = sol.minWindow2("acbdbaab", "aabd");*/

	//Solution77 sol;
	//vector<vector<int>> res = sol.combine(4, 2);

	//Solution79 sol;
	//vector<vector<char>> board;
	//char a[2] = { 'a','b' };
	//vector<char> a1(a, a + 2);
	//board.push_back(a1);

	//char b[2] = { 'c', 'd' };
	//vector<char> b1(b, b + 2);
	//board.push_back(b1);
	//char c[4] = { 'A', 'D', 'E', 'E' };
	//vector<char> c1(c, c + 4);
	////board.push_back(c1);
	////char d[4] = { 'A', 'B', 'C', 'E' };
	////vector<char> d1(d, d + 4);
	////board.push_back(d1);
	//bool res = sol.exist(board, "acdb");

	/*Solution81 sol;
	int a[2] = { 1,3 };
	vector<int> nums(a, a + 2);
	bool res = sol.search(nums,3);*/

	/*Solution86 sol;
	ListNode* head = new ListNode(1);
	ListNode* sec = new ListNode(4);
	head->next = sec;
	ListNode* thir = new ListNode(3);
	sec->next = thir;
	ListNode* four = new ListNode(2);
	thir->next = four;
	ListNode* fi = new ListNode(5);
	four->next = fi;
	ListNode* six = new ListNode(2);
	fi->next = six;
	sol.partition(head,3);*/

	//Solution84 sol;
	//int a[7] = { 2,1,5,6,2,3,1};
	//vector<int> nums(a, a + 7);
	//int res = sol.largestRectangleArea2(nums);

	/*Solution88 sol;
	int a[3] = { 1, 3, 4 };
	vector<int> nums1(a, a + 3);
	nums1.push_back(0); nums1.push_back(0); nums1.push_back(0);
	int b[3] = { 2, 6, 8 };
	vector<int> nums2(b, b + 3);
	sol.merge2(nums1, 3, nums2, 3);*/

	/*Solution89 sol;
	vector<int> res = sol.grayCode2(0);*/

	/*Solution87 sol;
	bool res = sol.isScramble2("ab", "ba");*/

	/*Solution91 sol;
	int res = sol.numDecodings("10");*/

	//Solution92 sol;
	//ListNode* head = new ListNode(3);
	//ListNode* sec = new ListNode(5);
	//head->next = sec;
	//sol.reverseBetween(head, 1, 2);
	
	/*Solution93 sol;
	vector<string> res = sol.restoreIpAddresses("010010");*/

	//Solution97 sol;
	//bool res = sol.isInterleave("dbbca", "aabcc", "aadbbcbcac");
	
	/*Solution99 sol;
	TreeNode* root = new TreeNode(0);
	TreeNode* left = new TreeNode(1);
	root->left = left;
	sol.recoverTree(root);*/

	//Solution115 sol;
	//int res = sol.numDistinct("rarabbbit", "rabbit");
	
	/*Solution119 sol;
	vector<int> res = sol.getRows(3);*/

	//Solution118 sol;
	//vector<vector<int>> res = sol.generate(5);
//	Solution127 sol;
	//unordered_set<string> dict;
	//dict.insert("hot");
	//dict.insert("cog");
	//dict.insert("dog");
	//dict.insert("tot");
	//dict.insert("hog");
	//dict.insert("hop");
	//dict.insert("pot");
	//dict.insert("dot");
	////int res = sol.ladderLength2("hit", "cog", dict);

	//Solution126 sol;
	//vector<vector<string>> res = sol.findLadders("hot", "dog", dict);

	//Solution131 sol;
	//vector<vector<string>> res = sol.partition("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj");
	/*Solution132 sol;
	int res=sol.minCut2("cbbbcc");*/
	//Solution134 sol;
	//vector<int> gas;
	//gas.push_back(6);
	//gas.push_back(0);
	//gas.push_back(1);
	//gas.push_back(3);
	//gas.push_back(2);
	//vector<int> cost;
	//cost.push_back(4);
	//cost.push_back(5);
	//cost.push_back(2);
	//cost.push_back(5);
	//cost.push_back(5);
	//int res = sol.canCompleteCircuit2(gas, cost);

	//Solution140 sol;
	//unordered_set<string> dict;
	//dict.insert("aaaa");
	//dict.insert("aa");
	//dict.insert("a");
	////dict.insert("sand");
	////dict.insert("dog");
	//vector<string> res = sol.wordBreak("aaaaaaa", dict);

	//Solution148 sol;
	//ListNode* head = new ListNode(3);
	//ListNode* sec = new ListNode(1);
	//ListNode* thr = new ListNode(3);
	//ListNode* f = new ListNode(2);
	//head->next = sec;
	//sec->next = thr;
	//thr->next = f;
	//ListNode* res=sol.sortList(head);
	//sol.reorderList(head);
	//Solution145 sol;
	//TreeNode* root=new TreeNode(1);
	//TreeNode* right = new TreeNode(2);
	//root->right = right;
	//sol.postorderTraversal(root);
	/*Solution151 sol;
	string s = "   ";
	sol.reverseWords(s);*/
	/*int s[3] = {1,2,1};
	vector<int> s1(s,s+3);
	Solution162 sol;
	int res = sol.findPeakElement(s1);*/
	//Solution165 sol;
	//int res = sol.compareVersion("0010.0", "00010");
	//Solution168 sol;
	//string res = sol.convertToTitle(57);
	/*Solution172 sol;
	int res = sol.trailingZeros(50);*/
	/*Solution166 sol;
	string res = sol.fractionToDecimal(-1,INT_MIN);*/
	
	//Solution174 sol;
	//int s1[3] = { -2,-3,3 };
	//int s2[3] = { -5, -10, 1 };
	//int s3[3] = { 10, 30, -5 };
	//vector<int> s11(s1,s1+3);
	//vector<int> s22(s2, s2 + 3);
	//vector<int> s33(s3, s3 + 3);
	//vector<vector<int>> s;
	//s.push_back(s11);
	//s.push_back(s22);
	//s.push_back(s33);
	//int res = sol.calculateMinimumHP2(s);

//Solution187 sol;
//vector<string> res = sol.findRepeatedDnaSequences2("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

//Solution179 sol;
//int s1[2] = { 0,1};
//vector<int> s11(s1, s1 +2);
//string res = sol.largestNumber2(s11);

//Solution191 sol;
//int res = sol.hammingWeight(1);
//Solution188 sol;
//vector<int> n;
//n.resize(10000000);
//sol.maxProfit(100000000, n);

//Solution190 sol;
//unsigned int a = sol.reverseBits(1);

//Solution202 sol;
//bool res = sol.isHappy(2);

	//Solution207 sol;
	//vector<pair<int, int>> pre;
	//pre.push_back(make_pair(2,0));
	//pre.push_back(make_pair(2,1));
	//pre.push_back(make_pair(1,7));
	//pre.push_back(make_pair(5,9));
	//pre.push_back(make_pair(1,8));
	//pre.push_back(make_pair(3,4));
	//pre.push_back(make_pair(0,6));
	//pre.push_back(make_pair(0,7));
	//pre.push_back(make_pair(0,3));
	//pre.push_back(make_pair(8,9));
	//bool res = sol.canFinish(3, pre);
	/* Trie trie;
	 trie.insert("a");
	 trie.search("a");*/
	//Solution209 sol;
	//int s1[3] = { 1,4,4 };
	//vector<int> s11(s1, s1 +3);
	//int res = sol.minSubArrayLen(4, s11);

	// WordDictionary wordDictionary;
	// wordDictionary.addWord("bade");
	// wordDictionary.addWord("dad");
	// wordDictionary.addWord("bbs");
	//// bool res1=wordDictionary.search("pad");
	// //bool res2 = wordDictionary.search("bad");
	// //bool res3 = wordDictionary.search(".ad");
	// bool res4 = wordDictionary.search("b..");
//
//Solution214 sol;
//string res = sol.shortestPalindrome2("abcd");

//Solution215 sol;
//int s1[7] = { 5,2,4,1,3,6,0 };
//vector<int> s11(s1, s1 +7);
//int res = sol.findKthLargest2(s11,4);
//
//Solution216 sol;
//vector<vector<int>> res = sol.combinationSum3(3, 9);

//Solution218 sol;

//vector<vector<int>> build;
//int s1[3] = { 5,10,6 };
//vector<int> s11(s1, s1 +3);
//int s2[3] = { 6, 12, 8 };
//vector<int> s21(s2, s2 + 3);
//int s3[3] = { 7, 9, 9 };
//vector<int> s31(s3, s3 + 3);
//int s4[3] = { 8, 11, 7 };
//vector<int> s41(s4, s4 + 3);
//int s5[3] = { 15, 20, 7 };
//vector<int> s51(s5, s5 + 3);
//int s6[3] = { 15, 20, 12 };
//vector<int> s61(s6, s6 + 3);
//int s7[3] = { 20,25, 7 };
//vector<int> s71(s7, s7 + 3);
//build.push_back(s11);
//build.push_back(s21);
//build.push_back(s31);
//build.push_back(s41);
////build.push_back(s51);
////build.push_back(s61);
////build.push_back(s71);
//vector<pair<int, int>> res = sol.getSkyline2(build);

//Solution221 sol;
//vector<vector<char>> s;
//char s1[2] = {'0','1'};
//vector<char> s11(s1, s1 + 2);
//s.push_back(s11);
//char s2[2] = { '0', '1' };
//vector<char> s21(s2, s2 + 2);
//s.push_back(s21);
//int res = sol.maximalSquare(s);
//
//Solution224 sol;
//int res = sol.calculate("(1+(4+5+2)-3)+(6+8)");
//
//Solution227 sol;
//int res = sol.calculate2(" -3-4+5 / 2 ");

//Solution233 sol;
//int res = sol.countDigitOne(122);
//Solution257 sol;
//TreeNode* root = new TreeNode(4);
//root->left = new TreeNode(3);
//root->right = new TreeNode(6);
//root->left->left = new TreeNode(1);
//root->right-> left= new TreeNode(5);
////root->left->left->left = new TreeNode(8);
//root->left->left->right = new TreeNode(2);
//vector<string> res=sol.binaryTreePaths(root);

//Solution241 sol;
//vector<int> res = sol.diffWaysToCompute("2*3-4*5");
//
//Solution264 sol;
//int res = sol.nthUglyNumber2(10);
//
//Solution279 sol;
//int res = sol.numSquares2(257);

//Solution273 sol;
//string res = sol.numberToWords(1234124);

Solution282 sol;
vector<string> res=sol.addOperators("3456237490", 9191);
	system("pause");
	return 0;
}