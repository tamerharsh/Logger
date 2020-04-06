#ifndef LOGGER_LIB_HPP
#define LOGGER_LIB_HPP

#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "fmt/format.h"
#include "fmt/ostream.h"

#define FLAG_ON(...)  logger::Logging::extract_all_credentials(__DATE__,__TIME__,__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#define FLAG_OFF(...)	logger::Logging::extract_minimimal_credentials(__DATE__,__TIME__)	


namespace logger
{

	//Defining log level with severity levels.
	enum class LEVEL :int { OFF = 0, FATAL = 1, ERROR, WARN, DEBUG, TRACE = 5 };
	
	//Logs the credentials.:date, time,file_name,function_name,line_number,logger_name,logger_level,message.
	//Written in chronological order.	
	struct  LogCredentials {
		std::string date="";
		std::string time="";
		std::string file_name="";
		std::string function_name="" ;
		int line=0;
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
		 
		//Formats the data .
		template<typename T=std::string>
		std::string format_data(T msg_, logger::LEVEL,std::shared_ptr<logger::LogCredentials> any_credentails);

		//Check the Serverity level if  given level is below the specified return true else false.
		bool  check_severity_level(logger::LEVEL level);

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
	template<typename T>
	std::string  Logging::format_data(T msg_, logger::LEVEL level, std::shared_ptr<logger::LogCredentials> any_credentails)
	{

		auto message_in_string_format=fmt::to_string(msg_ );

		
		std::string level_in_string_format;
		
		//Converting log levels into strings.
		switch (level) 
		{
		case logger::LEVEL::OFF: level_in_string_format="OFF" ; break;
		case logger::LEVEL::FATAL: level_in_string_format="FATAL"; break;
		case logger::LEVEL::DEBUG: level_in_string_format="DEBUG"; break;
		case logger::LEVEL::WARN:  level_in_string_format="WARN" ; break;
		case logger::LEVEL::ERROR: level_in_string_format="ERROR"; break;
		case logger::LEVEL::TRACE: level_in_string_format="TRACE"; break;
	
		}

		//if  filename etc is empty display only logger level and msg else all credentials.
		if (!any_credentails->file_name.empty())
		{
			return  fmt::format("[Time]:{} - {}, [Logger]:{}, [File]:{}, [Function Name]:{}, [Line]:{} ,[Level]:{} ,[Message]:{}", any_credentails->date, any_credentails->time, any_credentails->logger_name, any_credentails->file_name, any_credentails->function_name, any_credentails->line, level_in_string_format, message_in_string_format);

		}
		else
		{
			return fmt::format("[Time]:{} - {}, [Logger]:{}, [Level]:{}, [Message]:{}", any_credentails->date, any_credentails->time, any_credentails->logger_name,  level_in_string_format, message_in_string_format);

		}
	
		bool logger::Logging::check_severity_level(logger::Logging level_)
		{
			
			return level_ <= severity_level ? true : false;
		
		}
	}

};
#endif LOGGER_LIB_HPP

