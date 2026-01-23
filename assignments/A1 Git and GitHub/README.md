# A1: Personal Academic Website on GitHub Pages

## Purpose and Objectives

* Establish a professional personal website hosted on GitHub Pages to present profile information (bio, CV, personal projects as applicable)
* GitHub Pages publishes a site automatically from a GitHub repository after configuration, typically accessible at https://<username>.github.io for a user site.

## Scope

1. **GitHub Pages site deployment**
   - Create and configure a GitHub Pages site `<username>.github.io`
     - Example: https://academicpages.github.io
2. **Template selection and customization**
   - Use either:
     - AcademicPages template repository (allowed), or
       - https://github.com/academicpages/academicpages.github.io
     - Any other static-site template/theme (e.g., Jekyll-based) compatible with GitHub Pages.
3. **Content publication**
   - Publish at minimum:
     - Home/landing page (short professional bio)
     - Contact information (professional email, affiliation, links GitHub)
4. **Command-line Git workflow**
   - All updates should be committed and pushed from the terminal/command line (no “upload via web UI” as the primary workflow).



## Implementation Plan (prefer CLI-Oriented)

- Create a public repo named: `<username>.github.io` (user site).
  - The contents of this repo can be https://github.com/academicpages/academicpages.github.io or use any GitHub Pages-compatible template (Jekyll theme, static HTML, etc.).
    - You can use git clone https://github.com/academicpages/academicpages.github.io and push to repo `<username>.github.io` on your GitHub.com
  - If using a GitHub paid or academic plan, the repository may be private; otherwise, the repository must be public for the site to be accessible
- Configure GitHub Pages in repository settings if needed (depending on template and GitHub defaults). 



## Acceptance Criteria

A submission is considered complete when all criteria below are met:

1. **Site is live** on GitHub Pages and loads without errors. 
2. **Required pages present**: Home, Personal Information
3. **Git history evidence**: Repository commit history shows multiple meaningful commits.
4. **If you already have such site, you may submit the URL of that site**
5. **Policy compliance**:
   - No restricted academic project source code is publicly exposed.
   - **ECE 3514 materials or assignment must be in a private repo and not in this repo.**