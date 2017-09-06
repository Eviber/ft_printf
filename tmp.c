int		ft_printf(const char *format, ...)
// init structure, envoie a parsing, si pas de bug, write, puis free

char	*parsing(t_printf *data, va_list lst, char *result, int i) 
// parse et envoie a analys

char	*analys(t_printf *data, va_list lst) 
// envoie a main flag puis  a analyse conversion si specifier connue sinon
// envoie a applyflag

void	main_flag(t_printf *data, int i, int state, int *option)
// check la presence des flags, et les stock dans opt

char	*analyse_conversion(va_list lst, t_printf *data, int i, int size)
// calcule la taille necessaire au ull_base, c est a dire les modifers de taille
// et apelle conversion

char	*set_conversion(va_list l, int opt, t_printf *data, int cas)
// en fonction du type de la conversion (deduit de la position en index dans la
// chaine sSpdDioOuUxXcC% et envoie les info necessaire (base, signe, upcase)

char	*get_lst(va_list lst, int opt, int cas, t_printf *data, ...)
//fonction ft_norme, pre cast la valeur du premier va list, et applique ft unice
// pour le grand S

char	*conversion(int cas, t_printf *d, char *res, va_list ol, ...)
// recupere les information precedement calculer ( nombre de
// bite a verifier, infomation face a laconversion (base, signe, upcase) et fait
// ull_base ou ft unic)

char	*unic(char *resultat, unsigned int *inf, char *res, t_printf *dt)/
// apelle ft_unic en boucle, puis cast le retour en char, puis decremente nombre
// de boucle a effecute

char	*ft_unic(char *elem, int i, int j, char *str)
// cree un masque bimaire , si mb curmax le permet, puis rajoute le str dnas le
// masque en le completant par la fin, puis remplis les x restant par des 0

char	*apply_flag(char *res, t_printf *data, int *option)
// envoie sur int_flag ou char_flag et aplliaue la largueur

char	*char_flag(char *res, int option[7], int length, t_printf *data)
// apllique les flags pour les chars(c = 0 , s= diminue);

char	*int_flag(char *res, int opt[7], char param, int len)
// apllique les flag de type int (# les flags + et - et space)

char	*add_to_str(char *res, char *str, int option, t_printf *data)
// realloc 
