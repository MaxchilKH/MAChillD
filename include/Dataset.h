#pragma once

#include<string>
#include<fstream>
#include<vector>
#include<memory>


class Data{

	public:
		enum TYPE {
			INDEXDATA,
		};
		static std::unique_ptr<Data> make_data(Data::TYPE type);  
		virtual void setData(const std::string&  line) = 0;
};

class IndexData : public Data{

public: 
	std::string   date;
    float    opening;
    float    highest;
    float    lowest;
    float    closing;
    
	void setData(const std::string& init_string);
};

class Dataset{

private: 
	std::vector<std::unique_ptr<Data>> data;
    std::fstream fhandle;

public: 
	int loadCSV(const std::string& filename, Data::TYPE DATATYPE);
    const std::vector<std::unique_ptr<Data>>& getData();
};
