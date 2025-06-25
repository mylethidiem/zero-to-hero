# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

# Path to your Oh My Zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load
ZSH_THEME="powerlevel10k/powerlevel10k"

# [FIXED] Consolidated all plugins into one list.
# The order is important, zsh-syntax-highlighting should ideally be last.
plugins=(
	git
	docker
	docker-compose
	history
	rsync
	safe-paste
	zsh-autosuggestions
	zsh-syntax-highlighting
)

# Load Oh My Zsh.
source $ZSH/oh-my-zsh.sh

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# --- USER CONFIGURATION & ALIASES ---
# All custom settings, aliases, and functions should go AFTER sourcing oh-my-zsh.sh

# --- Navigation ---
alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias ~="cd ~" # Go back to home directory

# --- File Listing (ls, exa) ---
alias l='ls -lFh'     # Detailed, human-readable, classified file list
alias la='ls -AlFh'    # List all files (including hidden files)
alias ll='ls -l'
alias lt='ls -ltFh'    # Sort by last modification time

# --- File/Directory Operations ---
alias md='mkdir -p' # Create parent directories if they don't exist
alias rd=rmdir

# --- Searching ---
alias f='find . -name' # Example: f "package.json"
alias grep='grep --color=auto' # Always colorize grep results

# --- System Management ---
alias update='sudo apt update && sudo apt upgrade -y' # Update system (example for Ubuntu/Debian)
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

# --- Git Aliases (Basic) ---
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
alias gs='git status -sb' # Short status (s = short, b = branch)
alias gst='git stash'
alias gstp='git stash pop'

# --- Git Aliases (Advanced Log / Graph) ---
alias glog="git log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
alias ggraph="git log --decorate --oneline --graph --abbrev-commit --format=format:'%C(bold yellow)%h%C(reset) %C(bold white)%<|(105,trunc)%s%C(reset) %C(bold dim green)%cL%C(reset) %C(bold magenta)(%ar %C(white)- %C(bold cyan)%cD)%C(reset) %C(auto)%d%C(reset) '"
alias ggraphstat="git log --decorate --oneline --graph --stat --abbrev-commit --format=format:'%C(bold yellow)%h%C(reset) %C(bold white)%s%C(reset) %C(bold dim green)%ce%C(reset) %C(bold magenta)(%ar %C(white)- %C(bold cyan)%cD)%C(reset)%C(auto)%d%C(reset) '"
alias ggraph10="git log -10 HEAD --decorate --oneline --graph --abbrev-commit --format=format:'%C(bold yellow)%h%C(reset) %C(bold white)%<|(105,trunc)%s%C(reset) %C(bold dim green)%cL%C(reset) %C(bold magenta)(%ar %C(white)- %C(bold cyan)%cD)%C(reset) %C(auto)%d%C(reset)'"
alias ggraphstat10="git log -5 HEAD --decorate --oneline --graph --stat --abbrev-commit --format=format:'%C(bold yellow)%h%C(reset) %C(bold white)%s%C(reset) %C(bold dim green)%ce%C(reset) %C(bold magenta)(%ar %C(white)- %C(bold cyan)%cD)%C(reset)%C(auto)%d%C(reset)'"
alias ggraphshort="git log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) %C(bold green)%ai%C(reset)%C(bold yellow)%d%C(reset) %C(white)%s%C(reset) %C(magenta)%an%C(reset)'"
alias glog10="git log -10 HEAD --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) %C(bold green)%ai%C(reset)%C(bold yellow)%d%C(reset) %C(white)%s%C(reset) %C(magenta)%an%C(reset)'"
alias glog10first="git log -10 HEAD --first-parent --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) %C(bold green)%ai%C(reset)%C(bold yellow)%d%C(reset) %C(white)%s%C(reset) %C(magenta)%an%C(reset)'"

# --- Git Aliases (Advanced Refs / Others) ---
alias gbranchref="git for-each-ref --format='%(color:bold red)%03 %04 %05 %06 %10 %(color:bold green)%(authordate:format:%D %I:%M %p)    %(align:30,left)%(color:bold magenta)%(creatordate:relative)%(end) %(align:30,left)%(color:bold yellow)%(authorname)%(end) %09 %(color:bold cyan)%(refname:strip=3)' --sort=authordate refs/remotes"
alias gtagref="git for-each-ref --format='%(color:bold red)%03 %04 %05 %06 %10 %(color:bold green)%(creatordate:format:%D %I:%M %p)    %(align:30,left)%(color:bold magenta)%(creatordate:relative)%(end) %(align:30,left)%(color:bold yellow)%(creator)%(end) %(align:30,left)%(color:bold cyan)%(refname)%(end)' --sort=creatordate refs/tags"
alias gunstage='git reset HEAD --'
alias galias='git config --show-origin --get-regexp alias'
alias gexternal='git config --file .gitmodules --get-regexp path'
alias gpullfull='git pull && git submodule update --init --recursive'
alias gpullsub='git submodule update --init --recursive'
alias gclonefull='git clone --recursive'
alias gremoteupdate='git remote update origin --prune && git branch -a'
alias gpatch='git diff --no-prefix --ignore-space-at-eol --ignore-cr-at-eol'
alias gpatch1='git diff --no-prefix --ignore-space-at-eol --ignore-cr-at-eol HEAD~1 HEAD~0'
alias gpatch2='git diff --no-prefix --ignore-space-at-eol --ignore-cr-at-eol --ignore-submodules=all HEAD~1 HEAD~0 ":!.git*" ":!*/CI_*" ":!*.aar" ":!*.jar" ":!*.so" ":!*.png"'
alias gpatch3='git diff -b --no-prefix --ignore-space-at-eol --ignore-cr-at-eol --ignore-submodules=all HEAD~1 HEAD~0 ":!.git*" ":!*/CI_*" ":!*.aar" ":!*.jar" ":!*.so" ":!*.png"'


# --- Complex Commands as Functions (Safer and more reliable) ---

# Shows remote branches with last commit details, sorted by date
function gbranchdetail() {
    for branch in $(git branch -r | grep -v HEAD); do
        echo "$branch __________ $(git show --format='[%ar] __________ by %an <%ae>' $branch | head -n 1)"
    done | sort -r
}

# [FIXED] Completed the gcleanup function with proper syntax and logic
# WARNING: Destructive cleanup function. Deletes ALL untracked files and resets EVERYTHING.
function gcleanup() {
    echo -e "\033[1;31mWARNING:\033[0m This will \033[1;31mPERMANENTLY DELETE\033[0m all untracked files/directories."
    echo "It will also reset your entire repository to the last commit (git reset --hard)."
    
    # Zsh specific prompt for y/n confirmation
    read -q "REPLY?Are you absolutely sure you want to proceed? (y/n) "
    echo "" # Newline after the prompt
    
    if [[ "$REPLY" =~ ^[Yy]$ ]]; then
        echo "Starting cleanup..."
        git clean -ffd && git rm --cached -r . && git reset --hard HEAD && git rm .gitattributes && git reset . && git checkout .  && git submodule deinit -f --all && git submodule update --init --recursive
        echo "Cleanup complete."
    else
        echo "Cleanup cancelled."
    fi
}