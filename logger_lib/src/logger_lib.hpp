#ifndef LOGGER_LIB_HPP
#define LOGGER_LIB_HPP

namespace logger
{
	//Defining log level with severity levels.
	enum class LEVEL :int { OFF = 0, FATAL = 1, ERROR, WARN, DEBUG, TRACE = 5 };

	//Logging clas logs the messages at various severity levels.
	class Logging
	{
	 public:
		//Ctor sets the severity level preferred by user.
		Logging(logger::LEVEL severity_level_=logger::LEVEL::TRACE);

	 private:
		//Severity level prefered by user.
		const LEVEL severity_level;
	};

	//Ctor implementation.
	Logging::Logging(logger::LEVEL severity_level_) :severity_level(severity_level_)
	{
	}
};

#endif LOGGER_LIB_HPP

