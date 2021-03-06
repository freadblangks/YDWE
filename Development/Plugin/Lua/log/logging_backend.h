#pragma once

#include <base/filesystem.h>

#if defined(LOG_EXPORTS)
#	define LOG_API __declspec(dllexport)
#else
#	define LOG_API __declspec(dllimport)
#endif

namespace logging
{
	class LOG_API backend
	{
	public:
		typedef char                          char_type;
		typedef std::basic_string<char_type>  string_type;
		typedef std::basic_ostream<char_type> stream_type;

	private:
		struct implementation;
		implementation* impl_;

	public:
		backend(const fs::path& root, const std::wstring& name);
		backend(backend&&);
		~backend();

		void consume(string_type const& formatted_message);
		void flush();
		void rotate_file();

		backend(backend&) = delete;
		void operator=(backend&) = delete;
	};
}
