//----------------------------------------------------
//
// Dataset
//
//
#include<string>
#include<fstream>
#include<vector>
#include<memory>


class Data{

    public static const int INDEXDATA = 1;

    public static std::unique_ptr<Data> make_data(int type);  

    public virtual void setData(std::vector<string>&  line) = 0;
}

class IndexData : public Data{

    public String   date;
    public float    opening;
    public float    highest;
    public float    lowest;
    public float    closing;
    
    void setData(std::string line);
}

class Dataset{

    private std::vector<unique_ptr<Data>> data;
    private std::fstream fhandle;

    public int loadCSV(std::string filename, int DATATYPE);
    public const std::vector<Data>& getData();
}
