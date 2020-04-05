#ifndef LOGGER_LIB_HPP
#define LOGGER_LIB_HPP

#include <memory>
#include <string>
#include <iostream>

#define FLAG_ON(...)  logger::Logging::extract_all_credentials(__DATE__,__TIME__,__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#define FLAG_OFF(...)	logger::Logging::extract_minimimal_credentials(__DATE__,__TIME__)	

namespace logger
{

	//Defining log level with severity levels.
	enum class LEVEL :int { OFF = 0, FATAL = 1, ERROR, WARN, DEBUG, TRACE = 5 };
	
	//Logs the credentials.:date, time,file_name,function_name,line_number,logger_name,logger_level,message.
	//Written in chronological order.	
	struct  LogCredentials {
		std::string date="null";
		std::string time = "null";
		std::string file_name = "null";
		std::string function_name = "null";
		int line = 0;
		std::string logger_name = "root";
	};

	//Logging clas logs the messages at various severity levels.
	class Logging
	{ 
		 public:
		
		//Ctor sets the severity level preferred by user.
		explicit Logging(logger::LEVEL severity_level_ = logger::LEVEL::TRACE);

		//Extract minimal info such as date and time.
		static std::shared_ptr <logger::LogCredentials>  extract_minimimal_credentials(std::string date_, std::string time_, ...);

		//Extarcts all the information about log.
		static std::shared_ptr<logger::LogCredentials>  extract_all_credentials(std::string date_, std::string time_, std::string file_name_, std::string func_name_, int line_, ...);

		//Method for capturing severity of type trace.
		template<typename T = std::string>
		bool trace(T msg_, std::shared_ptr<logger::LogCredentials> trace_credentials_=FLAG_OFF());

		private:
		
		//Severity level prefered by user.
		const logger::LEVEL severity_level;

	};	
	//Ctor implementation.
	logger::Logging::Logging(logger::LEVEL severity_level_) :severity_level(severity_level_)
	{
	}
	
    std::shared_ptr<logger::LogCredentials> logger::Logging::extract_minimimal_credentials(std::string date_, std::string time_, ...)
	{
		auto minimum_credentials_ptr =  std::make_shared<logger::LogCredentials>();
		minimum_credentials_ptr->time = time_;
		minimum_credentials_ptr->date = date_;
		
		return minimum_credentials_ptr;
	}

	std::shared_ptr<logger::LogCredentials> logger::Logging::extract_all_credentials(std::string date_, std::string time_, std::string file_name_, std::string func_name_, int line_, ...)
	{
		auto credentials_ptr = std::make_shared<logger::LogCredentials>();
		
		credentials_ptr->date = date_;
		credentials_ptr->time = time_;
		credentials_ptr->file_name = file_name_;
		credentials_ptr->function_name = func_name_;
		credentials_ptr->line = line_;

		return credentials_ptr;
	}

	template<typename T>
	bool logger::Logging::trace(T msg_, std::shared_ptr<logger::LogCredentials> trace_credentials_)
	{
		
		return false;

	}

};
#endif LOGGER_LIB_HPP

