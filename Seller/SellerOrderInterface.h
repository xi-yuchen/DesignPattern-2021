#ifndef DESIGNPATTERN_2021_SELLERORDERINTERFACE_H
#define DESIGNPATTERN_2021_SELLERORDERINTERFACE_H



using namespace std;

class SellerOrderInterface {
public:
	void displayOrder();
	void removeOrder();
	void hasOrder();

	void changeOrderStatus();
};


#endif //DESIGNPATTERN_2021_SELLERORDERINTERFACE_H