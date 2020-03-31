#ifndef LOGGER_LIB_HPP
#define LOGGER_LIB_HPP

#include <string>

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

		//Logs message at trace level.
		void trace(std::string& message_);

		private:

		//Severity level prefered by user.
		const LEVEL severity_level;
		
		//log_credentials.
		struct  LogCredentials
		{
			 logger::LEVEL level;
			 std::string message;
		};

		//stores the credentials such as LEVEL, message etc.
		LogCredentials store_credentials(logger::LEVEL, std::string&);

	};

	//Ctor implementation.
	Logging::Logging(logger::LEVEL severity_level_) :severity_level(severity_level_)
	{
	}

	Logging::LogCredentials Logging::store_credentials(logger::LEVEL level_, std::string& message_)
	{
		Logging::LogCredentials credentials;
		credentials.level = level_;
		credentials.message = message_;
		return  credentials;
	}
	
	void Logging::trace(std::string& message_)
	{
		auto trace_credentials=store_credentials(logger::LEVEL::TRACE, message_);


	}

};

#endif LOGGER_LIB_HPP

