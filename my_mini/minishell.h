#ifndef MINISHELL_H
#define MINISHELL_H

# include "./libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/stat.h>

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
	struct s_envp	*prev;
}	t_envp;

typedef struct s_mini
{
	char	*input;
	int		exit_status;
	int		fd0_source;
	int		fd1_source;
	int		fd2_source;
	int		launch_method;
	//t_prog	*apps;
	t_envp	*environment;
	int		argc;
	char	**argv;
}			t_mini;

int		ft_parser(t_mini *shell, int *i);
int		ft_preparser(t_mini *shell);
char	*ft_get_value(t_envp *env, char *key);
int		ft_dollar_status(t_mini *shell, int *i);
int		dollar_quote(t_mini *shell, int *i);
int		dollar_env(t_mini *shell, int *i, int start);
int		ft_dollar(t_mini *shell, int *i);
int		ft_strcmp(char *s1, char *s2);
t_envp	*ft_new_env(char *s);
t_envp	*ft_prev_env(t_envp *env);
void	ft_full_env(t_envp **env, t_envp *new);
void	get_env(t_mini *shell, char **envp);
int		ft_single_quote(t_mini *shell, int *i);
int		ft_double_quotes(t_mini *shell, int *i);
void	init_mini(t_mini *shell, char **argv, int argc);
void	ft_controlc(int sig);
void	ft_signal(void);
int		ft_clear_input(t_mini *shell);
int		ft_error_syntax(t_mini *shell, char *s, int len);


#endif