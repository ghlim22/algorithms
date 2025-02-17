#include <string>
class RunTimeException {
	public:
		RunTimeException(const std::string &err) : _errorMsg(err) {}
		const std::string &getMessage() const {return _errorMsg;}
	private:
	std::string _errorMsg;
};