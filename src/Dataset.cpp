#include <sstream>
#include "../include/Dataset.h"

std::unique_ptr<Data> Data::make_data(Data::TYPE type){
    
    switch(type){
	case Data::INDEXDATA: return std::make_unique<IndexData>(); break;
    }
    
}

void IndexData::setData(const std::string& init_string) {

	std::istringstream iss(init_string);

	iss >> date
		>> opening
		>> highest
		>> lowest
		>> closing;
}

int Dataset::loadCSV(const std::string& filename, Data::TYPE DATATYPE){
	
	fhandle.open(filename);

	for(std::string s; std::getline(fhandle, s); )
	{
		data.push_back(Data::make_data(DATATYPE));
		data.back()->setData(s);
	}
}

const std::vector<std::unique_ptr<Data>>& Dataset::getData() {

	return data;
}
