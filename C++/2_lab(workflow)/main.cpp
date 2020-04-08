
#include "worker.h"


int main(int argc, char **argv) {
  worker worker;
  worker.all_process(argv[1]);

    //parser p;
    //p.parse(argv[1]);
    //auto parsedText = p.getParsedText();
    //auto ex_order = p.getExOrder();
    //std::cout << parsedText[0].first << " " << parsedText[0].second[0]  << std::endl;
    //std::cout << parsedText[1].first << " " << parsedText[1].second[0] << " " << parsedText[1].second[1] << std::endl;
    //std::cout << parsedText[2].first << " " << parsedText[2].second[0] << std::endl;
    //std::cout << parsedText[3].first << std::endl;
    //std::cout << parsedText[5].first << " " << parsedText[5].second[0]  << std::endl;
    //std::cout << ex_order[0] << " " << ex_order[1] << " " << ex_order[2] << " " << ex_order[3] << " " << ex_order[4] << std::endl;
  return 0;
}