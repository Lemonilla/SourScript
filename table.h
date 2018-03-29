extern "C" uint32_t getNextLabel();
extern "C" uint32_t getNextLocation();
extern "C" void claimLabel(uint32_t l);

class tableEntry{};

class function : public tableEntry 
{
	public:
		std::string name;
		std::string returnType;
		uint32_t label;
		bool reservedLabel;
		function(std::string n, std::string rt)
		{
			name = n;
			returnType = rt;
			label = getNextLabel();
			reservedLabel = false;
		}
		function(std::string n, std::string rt, uint32_t label)
		{
			name = n;
			returnType = rt;
			claimLabel(label);
			reservedLabel = true;
		}
};

class variable : public tableEntry 
{
	public:
		std::string name;
		std::string type;
		std::string super_type;
		uint32_t location;
		variable(std::string n, std::string ty)
		{
			name = n;
			type = ty;
			location = getNextLocation();
		}
		variable(std::string n, std::string ty, std::string sup)
		{
			name = n;
			type = ty;
			super_type = sup;
			location = getNextLocation();
		}
};
