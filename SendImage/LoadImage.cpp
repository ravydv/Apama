#include <sag_connectivity_plugins.hpp>
#include <sag_connectivity_chain_managers.hpp>
#include <fstream>
using namespace com::softwareag::connectivity;


class LoadImage: public AbstractSimpleCodec
{
public:
	LoadImage(const CodecConstructorParameters &config)
		: AbstractSimpleCodec(config) {}

	virtual bool transformMessageTowardsHost(Message &m)
	{
		return false;
	}
	virtual bool transformMessageTowardsTransport(Message &m)
	{
	    map_t &payload = get<map_t>(m.getPayload());
	    std::ifstream is("kitten.jpeg", std::ios::binary);
	    if(is){
            is.seekg (0, is.end);
            size_t length = is.tellg();
            is.seekg (0, is.beg);
            buffer_t buffer{length};
            is.read ((char*)buffer.begin(),length);
            payload.insert("attachment", std::move(buffer));
	    }
		transportSide->sendBatchTowardsTransport(&m, &m+1);
		return false;
	}
};

SAG_DECLARE_CONNECTIVITY_CODEC_CLASS(LoadImage)

