import os
import shutil
import git

def deploy_and_update_noclue_coin():
    # Define paths
    desktop_noclue_path = r"C:\Users\admin\Desktop\noclue"
    project_dir = os.getcwd()
    github_repo_url = "https://github.com/hashmagic420/noclue"

    # Check if the folder exists on the desktop
    if os.path.exists(desktop_noclue_path):
        print("Found 'noclue' folder on Desktop. Integrating files...")
        
        # Initialize git repo if not already initialized
        if not os.path.exists(os.path.join(project_dir, '.git')):
            repo = git.Repo.init(project_dir)
        else:
            repo = git.Repo(project_dir)

        # Copy files from desktop folder to current project
        for item in os.listdir(desktop_noclue_path):
            s = os.path.join(desktop_noclue_path, item)
            d = os.path.join(project_dir, item)
            if os.path.isdir(s):
                shutil.copytree(s, d, dirs_exist_ok=True)
            else:
                shutil.copy2(s, d)

        # Add all files to git
        repo.git.add(A=True)

        # Commit changes
        repo.index.commit("Update from desktop folder")

        # Add remote if it doesn't exist
        try:
            origin = repo.remote('origin')
        except ValueError:
            origin = repo.create_remote('origin', github_repo_url)

        # Fetch the latest changes from the remote repository
        origin.fetch()

        # Pull changes from remote
        origin.pull(origin.refs[0].remote_head)

        # Push changes to remote
        origin.push()

        print("NoClueCoin codebase has been deployed, updated, and pushed to GitHub successfully!")
    else:
        print(f"Error: 'noclue' folder not found at {desktop_noclue_path}")

if __name__ == "__main__":
    deploy_and_update_noclue_coin()

