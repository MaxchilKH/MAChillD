#include "../include/Dataset.h"

Data::make_data(int type){
    
    switch(type){
        case Data::INDEXDATA: return std::make_unique<IndexData>() break;
    }
    
}
