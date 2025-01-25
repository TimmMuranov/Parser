#include <string>
std::string help = 
"Доступные команды: 'h' (выводит это меню)\n"
"'lp' (linksParser), 'gth' (getTagHead), 'ce' (contentExtruder).";

std::string help_lp = 
"linksParser принимает имя текстового документа.\n"
"Выводит список встреченных в нем ссылок (видны лишь ссылки в двойных кавычках).";

std::string help_gth = 
"getTagHead Принимает тег. Возвращает тег без спецификаций (<a id=1> ---> <a>, </a>).";

std::string help_ce = 
"contentExtruder принимает текст, стартовый тег со спецификаторами и его тип (пустой вариант тега)\n"
"('...<a>txt</a>...<a id=1>txt1</a>...', <a id=1>, <a> ---> 'txt1')";