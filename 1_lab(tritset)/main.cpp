//#include "tritset.h"
//
//
//int main() {
//	tritset set1(4), set2(4);
//	set1[0] = trit::True;
//	set1[1] = trit::False;
//	set1[2] = trit::True;
//	set1[3] = trit::Unknown;
//	std::cout << "printing all created set1: " << std::endl;
//	std::cout << set1[0] << " " << set1[1] << " " << set1[2] << " " << set1[3] << std::endl << std::endl;
//	std::cout << "printing all created set2: " << std::endl;
//	std::cout << set2[0] << " " << set2[1] << " " << set2[2] << " " << set2[3] << std::endl << std::endl;
//	set2 = set1;
//	std::cout << "printing all set2 after set2 = set1: " << std::endl;
//	std::cout << set2[0] << " " << set2[1] << " " << set2[2] << " " << set2[3] << std::endl << std::endl;
//	std::cout << "size_trits: " << set1.capacity() << std::endl << std::endl;
//	std::cout << "true cardinality: " << set1.cardinality(trit::True) << std::endl;
//	set1.shrink();
//	std::cout << "size_trits after .shrink(): " << set1.capacity() << std::endl << std::endl;
//	set1.trim(1);
//	std::cout << "printing set after .trim(1): " << std::endl;
//	std::cout << set1[0] << " " << set1[1] << " " << set1[2] << " " << set1[3] << std::endl << std::endl;
//	std::cout << "testing .cardinality() for set2: " << std::endl;
//	std::unordered_map<trit, int> count;
//	count = set2.cardinality();
//	if (set1[0] == set1[0]) { std::cout << "NIKITA LOH!"; }
//	std::cout << "true: " << count[trit::True] << std::endl << "false: " << count[trit::False] << std::endl << "unknown: " << count[trit::Unknown] << std::endl << std::endl;
//    return 0;
//} 