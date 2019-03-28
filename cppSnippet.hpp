template<typename T>
std::tuple<T> ParseElem(const std::string& elem) {

}
template<>
inline std::tuple<int> ParseElem<int>(const std::string& elem) {
	return std::make_tuple(std::stoi(elem));
}
template<>
inline std::tuple<std::string> ParseElem<std::string>(const std::string& elem) {
	return std::make_tuple(elem);
}

template <typename T, typename... Args>
std::tuple<T, Args...> ParseStrHelper(std::vector<std::string>& paramV) {
	std::string elem = paramV.back();
	paramV.pop_back();

	return std::tuple_cat(ParseElem<T>(elem),
		ParseStr<Args...>(paramV));
}

template <typename... Args>
std::tuple<Args...> ParseStr(std::vector<std::string>& paramV)
{
	return ParseStrHelper<Args...>(paramV);
}
template<>
inline std::tuple<> ParseStr<>(std::vector<std::string>& paramV) {
	return std::make_tuple();
}
