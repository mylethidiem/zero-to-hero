
# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:$HOME/.local/bin:/usr/local/bin:$PATH

# Path to your Oh My Zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time Oh My Zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="powerlevel10k/powerlevel10k"
# ZSH_THEME="robbyrussell"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(
	git
	docker
	docker-compose
	history
	rsync
	safe-paste
)

plugins=(git zsh-autosuggestions)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='nvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch $(uname -m)"

# Set personal aliases, overriding those provided by Oh My Zsh libs,
# plugins, and themes. Aliases can be placed here, though Oh My Zsh
# users are encouraged to define aliases within a top-level file in
# the $ZSH_CUSTOM folder, with .zsh extension. Examples:
# - $ZSH_CUSTOM/aliases.zsh
# - $ZSH_CUSTOM/macos.zsh
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
# --- Navigation ---
alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias ~="cd ~" # Go back to home directory

# --- File Listing (uses lsd or exa if installed, otherwise ls) ---
# Option 1: Using default 'ls'
alias l='ls -lFh'     # Detailed, human-readable, classified file list
alias la='ls -AlFh'    # List all files (including hidden files)
alias ll='ls -l'
alias lt='ls -ltFh'    # Sort by last modification time

# Option 2: If you have 'exa' installed (a modern replacement for ls)
# alias ls='exa'
# alias l='exa -lFh --git'
# alias la='exa -AlFh --git'
# alias ll='exa -l'
# alias lt='exa -ltFh --git'

# --- File/Directory Operations ---
alias md='mkdir -p' # Create parent directories if they don't exist
alias rd=rmdir

# --- Searching ---
alias f='find . -name' # Example: f "package.json"
alias grep='grep --color=auto' # Always colorize grep results

# --- Git ---
alias g='git'
alias ga='git add'
alias gaa='git add -A' # Add all changes
alias gap='git add -p' # Add changes interactively
alias gb='git branch'
alias gc='git commit -v'
alias gcm='git commit -m'
alias gco='git checkout'
alias gcb='git checkout -b' # Create and switch to a new branch
alias gd='git diff'
alias gds='git diff --staged' # View staged changes
alias gf='git fetch'
alias gl='git pull'
alias gp='git push'
alias gpf='git push --force-with-lease' # A safer force push than 'git push --force'
alias glog="git log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit" # A prettier and clearer log
alias gs='git status -sb' # Short status (s = short, b = branch)
alias gst='git stash'
alias gstp='git stash pop'

# --- System Management ---
alias update='sudo apt update && sudo apt upgrade -y' # Update system (example for Ubuntu/Debian)

# --- Process Management ---
alias top='htop' # Use htop if installed, it's much better than top
alias psg="ps aux | grep -v grep | grep -i -e VSZ -e" # Search for a process

# --- Networking ---
alias ipa='ip -c a' # Display colored IP addresses
alias myip='curl ifconfig.me' # Get public IP address

# --- Cleanup ---
alias cls='clear' # Like the 'cls' command on Windows

# --- Quick Open ---
alias edit='code' # Replace 'code' with your editor of choice, e.g., 'nvim', 'subl'
alias zshconfig='code ~/.zshrc' # Open Zsh config file with VS Code
alias reload='source ~/.zshrc' # Reload zsh config

# --- Current Path ---
alias p='pwd | tr -d "\n" | pbcopy' # Copy current path to clipboard (requires pbcopy on macOS, or xclip on Linux)

# --- Protection from silly mistakes ---
alias rm='rm -i'       # Ask before deleting
alias cp='cp -i'       # Ask before overwriting
alias mv='mv -i'       # Ask before overwriting

# --- History ---
alias h='history'

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh
plugins=( git zsh-syntax-highlighting zsh-autosuggestions )
